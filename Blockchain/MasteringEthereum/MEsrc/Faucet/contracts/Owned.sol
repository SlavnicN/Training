//SPDX-License-Identifier: UNLICENSED
// Our first contract is a faucet
pragma solidity ^0.8.11;

contract Owned{
    address payable owner;

    constructor(){
        owner = payable(msg.sender);
    }

    //This will be apply at first on any function it's 
    // added 
    modifier onlyOwner {
        require(msg.sender == owner);
        _;
    }
}