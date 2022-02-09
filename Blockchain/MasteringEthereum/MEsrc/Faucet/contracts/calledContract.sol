//SPDX-License-Identifier: UNLICENSED
// Our first contract is a faucet
pragma solidity ^0.8.11;

contract calledContract{
    event callEvent(address sender, address origin, address from);
    function calledFunction() public{
        emit callEvent(msg.sender, tx.origin, address(this));
    }
}
