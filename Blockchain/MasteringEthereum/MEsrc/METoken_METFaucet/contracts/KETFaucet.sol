//SPDX-License-Identifier: UNLICENSED
// Our first contract is a faucet
pragma solidity ^0.8.11;
import "@openzeppelin/contracts/token/ERC20/ERC20.sol";

//A faucet for ERC20 token KET
contract KETFaucet {
    ERC20 public KassosToken;
    address public KETOwner;

    //METFaucet constructor, provide the address of KassosToken contract and
    //the owner address we will be approved to transferFrom
    constructor(address _KasssosToken, address _KETOwner) {
        KassosToken = ERC20(_KasssosToken);
        KETOwner = _KETOwner;
    }

    function withdraw(uint withdraw_amount) public{

        //Limit withdrawal amount to 10 KET
        require(withdraw_amount <= 1000);
        //Use the transferFrom function of KETToken
        KassosToken.transferFrom(KETOwner, msg.sender, withdraw_amount);
    }

     //Accept any uncoming amount
    fallback () external payable {
        revert();
    }

    receive () external payable {
        revert();
    }
}