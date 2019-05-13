function greeting(name) {
  console.log(`Hello ${name}, welcome to ISS-Lab!`);
}

function introduction(firstName, lastName, callback) {
  const fullName = `${firstName} ${lastName}`;

  callback(fullName);
}

introduction('Mugdha','Abhyankar', greeting);