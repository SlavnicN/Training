var DeedRepository = artifacts.require("DeedRepository");
var AuctionRepository = artifacts.require("AuctionRepository");

module.exports = function(deployer){
    //Deploy the KassosToken contract as our only task
    deployer.deploy(AuctionRepository);
    deployer.deploy(DeedRepository, "Ultra Auction NFT", "UANFT");
}