// SPDX-License-Identifier: MIT
pragma solidity ^0.8.16;

import "./IVote.sol";

//TODO put the right one
import "@openzeppelin/contracts/access/Ownable.sol";
import "@openzeppelin/contracts/access/AccessControl.sol";
import "@openzeppelin/contracts/security/Pausable.sol";

contract Vote is IVote, Ownable, AccessControl, Pausable {
    /**
     * Error log
     */
    error endTimeReached();
    error endTimeNotReached();

    /**
     * Roles
     */

    bytes32 public constant VOTERS_ROLE = keccak256("VOTERS_ROLE"); 

    uint256[] choices;
    address[] voters;
    uint256 start;
    uint256 end;
    string metadata;
    address creator;
    bool isClose = false;
    
    uint256 resultVote;

    mapping(uint256 => uint256) public listVotes;
    uint256 voteCount;


    modifier isNotClosed() {
       require(!isClose);
       _;
    }

    constructor(
        uint256[] memory choices_,
        address[] memory voters_,
        uint256 start_,
        uint256 end_,
        string memory metadata_
    ) {
        if (end_ < start_) {
            revert endTimeReached();
        }
        creator = msg.sender;
        choices = choices_;
        voters = voters_;
        start = start_;
        end = end_;
        metadata = metadata_;

        for (uint256 i = 0; i < voters.length; i++) {
            _grantRole(VOTERS_ROLE, voters[i]);
        }
    }

    function closed() external view returns (bool) {
        return block.timestamp > end;
    }

    function getChoicesCount() external view returns (uint256) {
        return choices.length;
    }

    function getVotersCount() external view returns (uint256) {
        return voters.length;
    }

    function votesCount() external view returns (uint256) {
        return voteCount;
    }

    function vote(uint256 choice)
        external
        whenNotPaused
        onlyRole(VOTERS_ROLE)
    {
        if (end < start) {
            revert endTimeReached();
        }
        listVotes[choice] += 1;
        voteCount += 1;
        emit Voted(msg.sender, choice);
    }

    function cancel() external onlyOwner isNotClosed{
        _pause();
        emit Canceled();
    }

    //TODO what to do when tie ?
    function closing() external {
        if (end > start) {
            revert endTimeNotReached();
        }
        resultVote = winner();
        isClose = true;
        emit Closed();
    }


    function winner() view internal returns(uint){
        uint tmp;
        for(uint i =0; i< choices.length;i++){
           if(tmp<listVotes[i]) tmp = listVotes[i];
        }
        return tmp;
    }
}
