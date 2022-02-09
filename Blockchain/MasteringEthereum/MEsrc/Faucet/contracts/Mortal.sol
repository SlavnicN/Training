//SPDX-License-Identifier: UNLICENSED
// Our first contract is a faucet
pragma solidity ^0.8.11;
import "./Owned.sol";

contract Mortal is Owned {
    //need the virtual if you want to be able to overide it
    //in child contract
    function destroy() virtual public onlyOwner{
        selfdestruct(owner);
    }
}