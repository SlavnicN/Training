// SPDX-License-Identifier: MIT
pragma solidity ^0.8.16;

interface IVote {
    
    //TODO do we really need this fucntion if we create storage var
    //function creator() external view returns (address);
    function closed() external view returns (bool);
    //function start() external view returns (uint);
    //function end() external view returns (uint);
    //function metadata() external view returns (string memory);

    //Same do we need this one
    //function choices(uint256) external view returns (bytes32, uint256);
    //Simple length get 
    function getChoicesCount() external view returns (uint);

    //Same do we need this one 
    //function voters(uint256) external view returns (address);
    //Simple get 
    function getVotersCount() external view returns (uint);
    
    //note sure I understand this one, return if an address has voted ?
    // what does it return
    //function votes(address) external view returns (uint256, bool, uint256);
    //Do I need a global variable 
    function votesCount() external view returns (uint);
   
    function vote(uint) external;
    //cancel a vote ? the smartcontract ? 
    function cancel() external;
    
    event Voted(address indexed voter, uint choice);
    event Canceled();
    event Closed();
}
