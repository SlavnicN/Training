var KassosToken = artifacts.require("KassosToken");
var Faucet = artifacts.require("Faucet");

module.exports = function(deployer){
    //Deploy the KassosToken contract as our only task
    deployer.deploy(KassosToken);
    deployer.deploy(Faucet);
}