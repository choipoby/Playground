function Dog(name) {
    this.name = name
}
Dog.prototype.sayMyName = function () {
    console.log(this.name)
}
const d = new Dog("Poby")
d.sayMyName()

// inheritance
function HuntingDog(name, breed) {
    Dog.call(this, name)
    this.breed = breed
}
// HuntingDog.prototype = Object.create(Dog.prototype)
const hd = new HuntingDog("Poby", "Jindo")
hd.sayMyName()