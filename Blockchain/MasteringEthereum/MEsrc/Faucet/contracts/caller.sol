//SPDX-License-Identifier: UNLICENSED
// Our first contract is a faucet
pragma solidity ^0.8.11;
import "./calledContract.sol";
import "./calledLibrary.sol";


contract caller{
    function make_calls(calledContract _calledContract) public {
        //Calling calledContract and calledLibrary directly
        _calledContract.calledFunction();
        calledLibrary.calledFunction();

        //Low-level calls using the address object for calledContract
        (bool success, bytes memory returnData) =address(_calledContract).call(abi.encode(bytes4(keccak256("calledFunction()"))));
        require(success);
        (success, returnData) =address(_calledContract).delegatecall(abi.encode(bytes4(keccak256("calledFunction()"))));
        require(success);
    }
}