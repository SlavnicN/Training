import { expect } from "chai";
import { ethers } from "ethers";
import 'dotenv/config'

//require("dotenv").config()
import EthersAdapter from '@gnosis.pm/safe-ethers-lib'
import SafeServiceClient from '@gnosis.pm/safe-service-client'
import Safe, { SafeFactory } from '@gnosis.pm/safe-core-sdk'
import { SafeAccountConfig } from '@gnosis.pm/safe-core-sdk'


const privateKey = process.env.PRIVATE_KEY;
const alchemy_goerli_api = process.env.ALCHEMY_GOERLI_API;

describe("Gnosis SDK test", function () {
    it("Should do stuff with Gnosis SDK", async function () {
        const provider = new ethers.providers.AlchemyProvider("goerli", alchemy_goerli_api);
        const signer = new ethers.Wallet(privateKey, provider);
        const ethAdapter = new EthersAdapter({ ethers, signer: signer });

        const txServiceUrl = 'https://safe-transaction.gnosis.io'
        const safeService = new SafeServiceClient({ txServiceUrl, ethAdapter })
        const safeFactory = await SafeFactory.create({ ethAdapter })

        const safeAccountConfig: SafeAccountConfig = {
          owners: ["0x8DBe4B09d226e047907fdBBa9320936C133D8F18"],
          threshold: 1,
        };

        const safeSdk = await safeFactory.deploySafe({ safeAccountConfig })

    });

});