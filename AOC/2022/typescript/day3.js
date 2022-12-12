"use strict";
exports.__esModule = true;
var fs = require("fs");
//import {LineByLine} from 'n-readlines'
//const liner = new LineByLine('./sample3-2.txt')
var file = fs.readFileSync('./input3.txt', 'utf8');
var lines = file.trim().split("\n");
function arrayOfValue() {
    var arr_alpha = new Array(52);
    for (var i = 0; i < arr_alpha.length / 2; i++) {
        arr_alpha[i] = String.fromCharCode("a".charCodeAt(0) + i);
    }
    for (var i = 0; i < arr_alpha.length / 2; i++) {
        arr_alpha[i + arr_alpha.length / 2] = String.fromCharCode("A".charCodeAt(0) + i);
    }
    return arr_alpha;
}
function part1(lines) {
    var arr_alpha = arrayOfValue();
    var res = 0;
    for (var _i = 0, lines_1 = lines; _i < lines_1.length; _i++) {
        var line = lines_1[_i];
        var newArr1 = new Array(line.length / 2);
        var newArr2 = new Array(line.length / 2);
        for (var i = 0; i < line.length; i++) {
            if (i < line.length / 2) {
                newArr1[i] = arr_alpha.indexOf(line[i]) + 1;
            }
            if (i >= line.length / 2) {
                newArr2[i - (line.length / 2)] = arr_alpha.indexOf(line[i]) + 1;
            }
        }
        for (var j = 0; j < line.length / 2; j++) {
            if (newArr1.includes(newArr2[j])) {
                res += newArr2[j];
                break;
            }
        }
    }
    return res;
}
function part2(lines) {
    var arr_alpha = arrayOfValue();
    var pack = [];
    var res = 0;
    for (var i = 0; i < lines.length; i++) {
        for (var j = 0; j < 3; j++) {
            pack[j] = lines[i++];
        }
        i--;
        console.log("packs:", pack);
        for (var j = 0; j < pack[0].length; j++) {
            if (pack[1].includes(pack[0][j]) && pack[2].includes(pack[0][j])) {
                res += arr_alpha.indexOf(pack[0][j]) + 1;
                console.log("includes:", arr_alpha.indexOf(pack[0][j]) + 1);
                break;
            }
        }
    }
    console.log(res);
}
part2(lines);
