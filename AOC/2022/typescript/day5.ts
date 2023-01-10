import * as fs from 'fs';

class Stack<T> {
  private array: T[]; 
    
  constructor(){
      this.array = [];
  }

  pop(): T | undefined {
    if (this.isEmpty()) 
      throw Error("Empty Stack");

    return this.array.pop();
  }

  push(data: T): void {
    this.array.push(data);
  }

  peek(): T {
    if (this.isEmpty()) 
      throw Error("Empty Stack");

    return this.array[this.array.length - 1];
  }
    
  printStack(){
    console.log(this.array);
  }
  isEmpty(): boolean {
    return this.array.length === 0;
  }
}

let file:string = fs.readFileSync('./sample5.txt','utf8');
let problem:string[] = file.split("\n\n");
let init:string[] = problem[0].split("\n");
let inst:string[] = problem[1].trim().split("\n");

let numStack:string[] = init[init.length-1].trim().split("   ");

let crate:string = init[0].slice(0,3);

let stack1:Stack<string> = new Stack<string>(); 
let stack2:Stack<string> = new Stack<string>(); 
let stack3:Stack<string> = new Stack<string>(); 

function initStack(){

    var line:string; 
    var sizeLine:number
    var crate1:string; 
    var crate2:string;
    var crate3:string;

    for(var i=init.length-2;i>=0;i--){
        line = init[i];
        crate1 = line.slice(0,3);
        crate2 = line.slice(4,7);
        crate3 = line.slice(8,11);


        stack1.push(crate1);
        stack2.push(crate2);
        stack3.push(crate3);
    }

    stack1.printStack();
    stack2.printStack();
    stack3.printStack();
}

initStack();
