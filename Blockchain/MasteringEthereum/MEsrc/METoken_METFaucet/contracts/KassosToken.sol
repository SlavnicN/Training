//SPDX-License-Identifier: UNLICENSED
// Our first contract is a faucet
pragma solidity ^0.8.11;

import "@openzeppelin/contracts/token/ERC20/ERC20.sol";

contract KassosToken is ERC20 {
    function decimals() public view virtual override returns (uint8) {
        return 2;
    }
    uint constant _initial_supply = 2100000000;

    constructor() ERC20("KassosToken","KET") {
        _mint(msg.sender, _initial_supply);
    }
}