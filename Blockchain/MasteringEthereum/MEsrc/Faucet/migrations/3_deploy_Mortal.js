var Mortal = artifacts.require("./Mortal.sol");
var CallContract = artifacts.require("./calledContract.sol");
var CallLibrary = artifacts.require("./calledLibrary.sol");
var caller = artifacts.require("./caller.sol");

module.exports = function(deployer){
    deployer.deploy(Mortal);
    deployer.deploy(CallContract);
    deployer.deploy(CallLibrary);
    deployer.link(CallLibrary, caller);
    deployer.deploy(caller);
}
