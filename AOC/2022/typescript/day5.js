"use strict";
exports.__esModule = true;
var fs = require("fs");
var Stack = /** @class */ (function () {
    function Stack() {
        this.array = [];
    }
    Stack.prototype.pop = function () {
        if (this.isEmpty())
            throw Error("Empty Stack");
        return this.array.pop();
    };
    Stack.prototype.push = function (data) {
        this.array.push(data);
    };
    Stack.prototype.peek = function () {
        if (this.isEmpty())
            throw Error("Empty Stack");
        return this.array[this.array.length - 1];
    };
    Stack.prototype.printStack = function () {
        console.log(this.array);
    };
    Stack.prototype.isEmpty = function () {
        return this.array.length === 0;
    };
    return Stack;
}());
var file = fs.readFileSync('./sample5.txt', 'utf8');
var problem = file.split("\n\n");
var init = problem[0].split("\n");
var inst = problem[1].trim().split("\n");
var numStack = init[init.length - 1].trim().split("   ");
var crate = init[0].slice(0, 3);
var stack1 = new Stack();
var stack2 = new Stack();
var stack3 = new Stack();
function initStack() {
    var line;
    var sizeLine;
    var crate1;
    var crate2;
    var crate3;
    for (var i = init.length - 2; i >= 0; i--) {
        line = init[i];
        crate1 = line.slice(0, 3);
        crate2 = line.slice(4, 7);
        crate3 = line.slice(8, 11);
        stack1.push(crate1);
        stack2.push(crate2);
        stack3.push(crate3);
    }
    //var firstLine:string = init[init.length-2];
    //var crate1:string = firstLine.slice(0,3);
    //var crate2:string = firstLine.slice(4,7);
    //var crate3:string = firstLine.slice(8,11);
    //stack1.push(crate1);
    //stack2.push(crate2);
    //stack3.push(crate3);
    //var firstLine:string = init[init.length-3];
    //var crate1:string = firstLine.slice(0,3);
    //var crate2:string = firstLine.slice(4,7);
    //var crate3:string = firstLine.slice(8,11);
    //stack1.push(crate1);
    //stack2.push(crate2);
    //stack3.push(crate3);
    //var firstLine:string = init[0];
    //var crate1:string = firstLine.slice(0,3);
    //var crate2:string = firstLine.slice(4,7);
    //var crate3:string = firstLine.slice(8,11);
    //stack1.push(crate1);
    //stack2.push(crate2);
    //stack3.push(crate3);
    stack1.printStack();
    stack2.printStack();
    stack3.printStack();
}
initStack();
