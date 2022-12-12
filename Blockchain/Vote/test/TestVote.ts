
import { time, loadFixture } from "@nomicfoundation/hardhat-network-helpers";
import { ethers } from "hardhat";

describe("Lock", function () {


    async function deployVoteSC() {
      const voteFactory = await ethers.getContractFactory("Vote");
      const [owner, addr1, addr2, addr3] = await ethers.getSigners();

      const THREE_DAYS_IN_SECS = 3 * 24 * 60 * 60;
      const choices = [1, 2, 3, 4, 5];
      const voters = [addr1.address, addr2.address, addr3.address];
      const startTime = await time.latest();
      const endTime = startTime + THREE_DAYS_IN_SECS;

      const voteContract = await voteFactory.deploy(
        choices,
        voters,
        startTime,
        endTime,
        ""
      );
      //TODO do we need to deployed ? or is the deploy enough here? 
      //await voteContract.deployed();
      return {owner, addr1, addr2, addr3, choices, voters, startTime, endTime, voteContract}
    }
    
  describe("Launching", function () {
    it("Should choices be", async function () {
        
    });
  });
});