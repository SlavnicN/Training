import * as fs from 'fs';

//import {LineByLine} from 'n-readlines'

//const liner = new LineByLine('./sample3-2.txt')

let file = fs.readFileSync('./input4.txt','utf8');
var lines = file.trim().split("\n");

function part1(lines:string[]){

    var low1
    var low2

    var high1 
    var high2 
    
    var pairs:string[]
    var elf1:string[]
    var elf2:string[]
    var counter = 0
    for(var line of lines){
        pairs = line.split(",")
        elf1 = pairs[0].split("-")
        elf2 = pairs[1].split("-")
        low1 = parseInt(elf1[0])
        low2 = parseInt(elf2[0])
        
        high1 = parseInt(elf1[1])
        high2 = parseInt(elf2[1])

        if(low1 <= low2 && high1 >= high2){ 
            console.log(pairs) 
            counter ++
            continue;
        }

        if(low1 >= low2 && high1 <= high2){ 
            console.log(pairs) 
            counter ++ 
            continue;
        }
    }

    return counter
}

function part2(lines:string[]){

    var low1
    var low2

    var high1 
    var high2 
    
    var pairs:string[]
    var elf1:string[]
    var elf2:string[]
    var counter = 0
    for(var line of lines){
        pairs = line.split(",")
        elf1 = pairs[0].split("-")
        elf2 = pairs[1].split("-")
        low1 = parseInt(elf1[0])
        low2 = parseInt(elf2[0])
        
        high1 = parseInt(elf1[1])
        high2 = parseInt(elf2[1])

        if(low1 <= low2 && high1 >= high2){ 
            console.log(pairs) 
            counter ++
            continue;
        }

        if(low1 >= low2 && high1 <= high2){ 
            console.log(pairs) 
            counter ++ 
            continue;
        }

        if(low2 >= low1 && low2 <= high1){ 
            console.log(pairs) 
            counter ++ 
            continue;
        }

        if(high2 >= low1 && high2 <= high1){ 
            console.log(pairs) 
            counter ++ 
            continue;
        }
    }

    return counter
}
console.log(part2(lines))
