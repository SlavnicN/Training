//SPDX-License-Identifier: UNLICENSED
// Our first contract is a faucet
pragma solidity ^0.8.11;

contract Owned{
    address payable owner;

    constructor(){
        owner = payable(msg.sender);
    }

    modifier onlyOwner {
        require(msg.sender == owner);
        _;
    }
}