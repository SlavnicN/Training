// SPDX-License-Identifier: SEE LICENSE IN LICENSE
pragma solidity ^0.8.16;

library LibError {
    error NotEnoughToken();
    error IncrementTooHigh();
    error AdminOrBalanceNotNull();
    error NotWhitelisted();
    error AlreadySigned();
    error AlreadyClosed();
}
