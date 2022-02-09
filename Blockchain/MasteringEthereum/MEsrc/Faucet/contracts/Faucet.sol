//SPDX-License-Identifier: UNLICENSED
// Our first contract is a faucet

pragma solidity ^0.8.11;
import "./Mortal.sol";

contract Faucet is Mortal{

    // need this for the contract Token, need to specify payable
    // if we want to send ether at construction time on Token side
    constructor() payable {}

    //index allow us to make it searchable in the app that will use this event
    event Withdrawal(address indexed to, uint amount);
    event Deposit(address indexed from, uint amount);

    //give out ether to anyone who asks
    function withdraw(uint withdraw_amount) public{
        //Limit withdraw amount 
        require(withdraw_amount < 0.1 ether);
        //Send the amount to the address that requested it
        require(address(this).balance >= withdraw_amount, "Insufficient balance in faucet for withdrawal request");
        payable(msg.sender).transfer(withdraw_amount);
        emit Withdrawal(msg.sender, withdraw_amount);
    }

    //Accept any uncoming amount
    fallback () external payable {
        emit Deposit(msg.sender, msg.value);
    }
    
    receive () external payable {
        emit Deposit(msg.sender, msg.value);
    }
}