

// implicit binding
const person = {
    name: "Poby",
    sayMyName: function () {
        console.log(`My name is ${this.name}`)
    }
}

// explicit binding
function sayMyName() {
    console.log(`My name is ${this.name}`)
}
sayMyName.call(person); // My name is Poby
sayMyName.apply(person); // My name is Poby
const boundSayMyName = sayMyName.bind(person);
//boundSayMyName(); // My name is Poby

// new binding
function Person(name) {
    // constructor
    this.name = name
}

Person.prototype.sayMyName = function () {
    console.log(`My name is ${this.name}`);
}

const p = new Person("Pby")
p.sayMyName(); // My name is Poby

// default binding
// globalThis.name = "Poby"
var name = "Poby"
function sayMyName() {
    console.log(`My name is ${this.name}`)
}
sayMyName(); // My name is undefined
