// helper fucntion
function helloSatyam(name) {
    console.log('Hello Satyam from ' + name);
}

// runner function
function processUserInput(extraWork) {
    let str = "Rahul"
    extraWork(str);
    return str;
}

let myString = processUserInput(helloSatyam);

console.log(myString)