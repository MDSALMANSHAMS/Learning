const person = {
    firstName: 'John',
    lastname: 'Smith',
    set fullName(value) {
        if (typeof value !== 'string'){
            throw new Error('Value is not a string.');
        }
        const parts = value.split(' ');
        if (parts.length !== 2) {
            throw new Error('Enter name');
        }
        this.firstName = parts[0];
        this.lastName = parts[1];
    }
};

try {
    person.fullName = null;
}

catch (err) {
    alert(err);
}

console.log(person);