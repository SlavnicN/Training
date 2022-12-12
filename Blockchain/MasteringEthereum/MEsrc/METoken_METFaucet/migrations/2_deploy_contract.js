var KassosToken = artifacts.require("KassosToken");
var KETFaucet = artifacts.require("KETFaucet");
//var accounts = web3.eth.getAccounts().then(function(acc){accounts=acc;});

//had trouble with the param of deploy, old version didn't use directly var accounts in the function 
//args, so here no need to call web3.eth.accounts (this also change we need to use getAccounts() now)
//Also had some trouble to migrate in truffle idk why, needed to restard truffle 
module.exports = function(deployer, network, accounts){
    //Deploy the KassosToken contract first
    deployer.deploy(KassosToken, {from: accounts[0]}).then(function(){
         //Then deploy KETFaucet and pass the address of KassosToken and the 
         //address of the owner of all the KET who will approve KETFaucet
         return deployer.deploy(KETFaucet, KassosToken.address, accounts[0]);
     })
}