// SPDX-License-Identifier: MIT
pragma solidity ^0.8.16;

import "@openzeppelin/contracts-upgradeable/token/ERC20/ERC20Upgradeable.sol";
import "@openzeppelin/contracts-upgradeable/token/ERC20/extensions/ERC20BurnableUpgradeable.sol";
import "@openzeppelin/contracts-upgradeable/security/PausableUpgradeable.sol";
import "@openzeppelin/contracts-upgradeable/proxy/utils/Initializable.sol";
import "@openzeppelin/contracts-upgradeable/proxy/utils/UUPSUpgradeable.sol";
import "@openzeppelin/contracts-upgradeable/access/AccessControlEnumerableUpgradeable.sol";

import "./LibError.sol";

contract CasinoTokenV1 is
    Initializable,
    ERC20Upgradeable,
    ERC20BurnableUpgradeable,
    PausableUpgradeable,
    AccessControlEnumerableUpgradeable,
    UUPSUpgradeable
{
    mapping(address => uint256) public _LiquidBalance;
    uint256 constant MAX_LIQUIDITY = 5000;

    uint256 public totalLiquideBalance;
    uint256 public navValue;
    address public owner;

    bytes32 public constant UPGRADER_ROLE = keccak256("UPGRADER_ROLE"); //Admin proxy for update
    bytes32 public constant MANAGER_INVESTOR_ROLE = keccak256("MANAGER_INVESTOR_ROLE");
    bytes32 public constant INVESTOR_ROLE = keccak256("INVESTOR_ROLE");
    bytes32 public constant WHITELIST_ROLE = keccak256("WHITELIST_ROLE");

    /**
     * Event
     */

    event IncrementLiquidity(address _addressToIncrementLiquidity, uint256 amount);
    event DecrementLiquidity(address _addressToIncrementLiquidity, uint256 amount);
    event UpdateNav(uint256 timestamp, uint256 _value);
    event ModifyAccountAddress(address oldAccount, address newAccount);

    /// @custom:oz-upgrades-unsafe-allow constructor
    constructor() {
        _disableInitializers();
    }

    function initialize() public initializer {
        __ERC20_init("CasinoToken", "CAST");
        __ERC20Burnable_init();
        __Pausable_init();

        //other init() for enumerable
        __AccessControl_init();
        __UUPSUpgradeable_init();

        _grantRole(DEFAULT_ADMIN_ROLE, _msgSender());
    }

    function decimals() public view virtual override returns (uint8) {
        return 0;
    }

    function pause() public onlyRole(DEFAULT_ADMIN_ROLE) {
        _pause();
    }

    function unpause() public onlyRole(DEFAULT_ADMIN_ROLE) {
        _unpause();
    }

    function mint(address to, uint256 amount) public onlyRole(DEFAULT_ADMIN_ROLE) {
        _mint(to, amount);
    }

    function transfer(address to, uint256 amount) public virtual override onlyRole(WHITELIST_ROLE) returns (bool) {
        super.transfer(to, amount);
    }

    //Add to whitelist
    function whitelist(address _addressToWhitelist) public onlyRole(DEFAULT_ADMIN_ROLE) {
        _grantRole(WHITELIST_ROLE, _addressToWhitelist);
    }

    //Blacklist user
    function blacklist(address _addressToBlacklist) public onlyRole(DEFAULT_ADMIN_ROLE) {
        _revokeRole(WHITELIST_ROLE, _addressToBlacklist);
    }

    //Increment liquidity balance
    function incrementLiquidity(address _addressToIncrementLiquidity, uint256 amount)
        public
        onlyRole(DEFAULT_ADMIN_ROLE)
    {
        if (amount + _LiquidBalance[_addressToIncrementLiquidity] >= balanceOf(_addressToIncrementLiquidity))
            revert LibError.NotEnoughToken();
        _incrementLiquidity(_addressToIncrementLiquidity, amount);
    }

    function _incrementLiquidity(address _addressToIncrementLiquidity, uint256 amount) internal {
        if (amount >= MAX_LIQUIDITY) revert LibError.IncrementTooHigh();
        _LiquidBalance[_addressToIncrementLiquidity] += amount;
        totalLiquideBalance += amount;
        emit IncrementLiquidity(_addressToIncrementLiquidity, amount);
    }

    //Decrement Liquidity balance
    function decrementLiquidity(address _addressToDecrementLiquidity, uint256 amount)
        public
        onlyRole(DEFAULT_ADMIN_ROLE)
    {
        _decrementLiquidity(_addressToDecrementLiquidity, amount);
        emit DecrementLiquidity(_addressToDecrementLiquidity, amount);
    }

    function _decrementLiquidity(address _addressToDecrementLiquidity, uint256 amount) internal {
        if (amount > _LiquidBalance[_addressToDecrementLiquidity]) {
            _LiquidBalance[_addressToDecrementLiquidity] = 0;
            //TODO test this more in depth
            if (amount > totalLiquideBalance) totalLiquideBalance = 0;
            else totalLiquideBalance -= _LiquidBalance[_addressToDecrementLiquidity];
        } else {
            _LiquidBalance[_addressToDecrementLiquidity] -= amount;
            totalLiquideBalance -= amount;
        }
    }

    //Update nav value
    function updateNav(uint256 value) public onlyRole(DEFAULT_ADMIN_ROLE) {
        navValue = value;
        emit UpdateNav(block.timestamp, value);
    }

    function modifyAccountAddress(address oldAccount, address newAccount) public onlyRole(DEFAULT_ADMIN_ROLE) {
        //Store liquid balance

        _grantRole(WHITELIST_ROLE, newAccount);
        uint256 Lbalance = _LiquidBalance[oldAccount];
        //Set LiquidBalance to the maximum to pass the transfer conditions
        _LiquidBalance[oldAccount] = balanceOf(oldAccount);

        _incrementLiquidity(newAccount, Lbalance);

        // transfer balance
        super._transfer(oldAccount, newAccount, balanceOf(oldAccount));

        _revokeRole(WHITELIST_ROLE, oldAccount);
        // transfer liquidity balance to new account

        emit ModifyAccountAddress(oldAccount, newAccount);
    }

    function allocateDividends() public onlyRole(DEFAULT_ADMIN_ROLE) {
        // TO BE IMPLEMENTED
    }

    function _beforeTokenTransfer(
        address from,
        address to,
        uint256 amount
    ) internal override whenNotPaused {
        if (!hasRole(DEFAULT_ADMIN_ROLE, msg.sender) && _LiquidBalance[from] <= 0)
            revert LibError.AdminOrBalanceNotNull();
        if (!hasRole(WHITELIST_ROLE, to) && to != address(0)) revert LibError.NotWhitelisted();
        super._beforeTokenTransfer(from, to, amount);
    }

    function _afterTokenTransfer(
        address from,
        address to,
        uint256 amount
    ) internal override whenNotPaused {
        //Decrement liquid balance
        _decrementLiquidity(from, amount);
        super._afterTokenTransfer(from, to, amount);
    }

    function _spendAllowance(
        address _owner,
        address spender,
        uint256 amount
    ) internal override {
        if (hasRole(DEFAULT_ADMIN_ROLE, msg.sender) == false) {
            super._spendAllowance(_owner, spender, amount);
        }
    }

    function _authorizeUpgrade(address newImplementation) internal override onlyRole(UPGRADER_ROLE) {}

    struct InvestorData {
        bool whitelisted;
        uint256 investorBalance;
        uint256 investoreLiquidity;
    }

    struct TokenData {
        uint256 totalLiquideBalance;
        uint256 totalSupply;
        bool paused;
        address[] investorList;
    }

    function getInvestoreData(address investor) public view returns (InvestorData memory) {
        bool whitelisted = hasRole(WHITELIST_ROLE, investor);
        uint256 investorBalance = balanceOf(investor);
        uint256 investorLiquidity = _LiquidBalance[investor];

        InvestorData memory data = InvestorData(whitelisted, investorBalance, investorLiquidity);
        return data;
    }

    function getTokenData() public view returns (TokenData memory) {
        uint256 invListLenght = getRoleMemberCount(INVESTOR_ROLE);
        address[] memory investorList = new address[](invListLenght);

        for (uint256 i = 0; i < invListLenght; i++) {
            investorList[i] = getRoleMember(INVESTOR_ROLE, i);
        }

        TokenData memory tokendata = TokenData(totalLiquideBalance, totalSupply(), paused(), investorList);

        return tokendata;
    }
}
