//SPDX-License-Identifier: UNLICENSED
// Our first contract is a faucet
pragma solidity ^0.8.11;
import "./Owned.sol";

contract Mortal is Owned {
    function destroy() public onlyOwner{
        selfdestruct(owner);
    }
}