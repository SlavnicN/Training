"use strict";
exports.__esModule = true;
var fs = require("fs");
//(1 for Rock, 2 for Paper, and 3 for Scissors) 
//(0 if you lost, 3 if the round was a draw, and 6 if you won).
// A  Rock
// B  Paper
// C  Scissors
// X need to lose
// Y need draw
// Z need to win 
var results = 0;
var file = fs.readFileSync('./input.txt', 'utf8');
file = file.replace(/A/g, "1");
file = file.replace(/X/g, "1");
file = file.replace(/B/g, "2");
file = file.replace(/Y/g, "2");
file = file.replace(/C/g, "3");
file = file.replace(/Z/g, "3");
var lines = file.split("\n");
for (var _i = 0, lines_1 = lines; _i < lines_1.length; _i++) {
    var line = lines_1[_i];
    var first = parseInt(line[0]);
    var second = parseInt(line[2]);
    //loose
    if ((first == 1 && second == 1) || (first == 2 && second == 1) || (first == 3 && second == 1)) {
        if (first == 1) {
            results += 3;
        }
        if (first == 2) {
            results += 1;
        }
        if (first == 3) {
            results += 2;
        }
    }
    //draw
    if ((first == 1 && second == 2) || (first == 2 && second == 2) || (first == 3 && second == 2)) {
        if (first == 1) {
            results += 1 + 3;
        }
        if (first == 2) {
            results += 2 + 3;
        }
        if (first == 3) {
            results += 3 + 3;
        }
    }
    //win
    if ((first == 1 && second == 3) || (first == 2 && second == 3) || (first == 3 && second == 3)) {
        if (first == 1) {
            results += 2 + 6;
        }
        if (first == 2) {
            results += 3 + 6;
        }
        if (first == 3) {
            results += 1 + 6;
        }
    }
}
console.log(results);
