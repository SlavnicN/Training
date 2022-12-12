import { HardhatUserConfig } from "hardhat/config";
import "@nomicfoundation/hardhat-toolbox";

import 'dotenv/config'
const privateKey = process.env.PRIVATE_KEY;
const https = process.env.ALCHEMY_HTTP;

const config: HardhatUserConfig = {
    networks: {
        rinkeby: {
            url: "https://eth-rinkeby.alchemyapi.io/v2/123abc123abc123abc123abc123abcde",
            accounts: {
                mnemonic: "test test test test test test test test test test test junk",
                path: "m/44'/60'/0'/0",
                initialIndex: 0,
                count: 20,
                passphrase: "",
            },

        },

        goerli: {
            url: https,
            accounts: [`0x${privateKey}`],
        },
    },

  solidity: "0.8.17",
};

export default config;
