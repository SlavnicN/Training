//SPDX-License-Identifier: UNLICENSED
// Our first contract is a faucet
pragma solidity ^0.8.11;

import "./Faucet.sol";

contract Token is Mortal{
    Faucet _faucet;

    //creat a new contract Faucet owned by this contract 
    //Token
    //constructor(){
    //    _faucet = new Faucet{value: 0.5 ether}();
    //}

    //This is if you want to call a contract
    //from a existing Faucet by specifing the address
    //It's riskier since we don't know if the address provided is 
    //Faucet or smth else
    //constructor(address payable _f){
    //    _faucet = Faucet(_f);
    //    _faucet.withdraw(0.1 ether);
    //}

    //Lower-level call, EVM opcode
    //have even more flexibility over precedent, but need to be more careful
    //help with contrcat that do not adhere to ABI or more controle over the encoding 
    //needed
    constructor(address _f){    
        (bool success, bytes memory returnData) = _f.call(abi.encode("withdraw", 0.1 ether));
        require(success);
    }

    // Here, we only specify `override` and not `virtual`.
    // This means that contracts deriving from `Token`
    // cannot change the behaviour of `destroy` anymore.
    function destroy() public override onlyOwner{
        _faucet.destroy();
    }
}