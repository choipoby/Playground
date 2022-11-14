let a = 1;
function outer() {
    let b = 2;
    function inner() {
        let a = 11;
        let b = 22;
        let c = 3;
        console.log(a, b, c);
    }

    inner()
    console.log(a, b);
}
outer()
console.log(a)

// es5
function mult(x, y) {
    return x * y;
}
function curriedMult(x) {
    return function (y) {
        return x * y;
    }
}
console.log(mult(2, 3))

const closured = curriedMult(3);
// javascript currying is implemented by the closure 
// each specialized function uses closure to keep the state.
// closured <= function (y) {
//     3 + y;
// }
console.log(closured(5));

// ES6
const add = (x, y) => x + y
const curriedAdd = x => y => x + y
console.log(add(1, 2))
console.log(curriedAdd(1)(2))

