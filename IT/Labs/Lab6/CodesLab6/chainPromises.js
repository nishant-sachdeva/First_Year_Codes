var weather = true
var date    = new Promise(function(resolve, reject) {
  if (weather) {
    var dateDetails = {
      name:     'XYZ Restaurant',
      location: 'Charminar',
    };

    resolve(dateDetails)
  } else {
    reject(new Error('Bad weather, so no Date'))
  }
});


var orderUber = function(dateDetails) {
  var message = `Get me an Uber ASAP to ${dateDetails.location}, we are going on a date!`;
  return Promise.resolve(message)
} 

var myDate = function() {
  date
    .then(orderUber)
    .then(function(done) {
      console.log(done);
    })
    .catch(function(error) {
      console.log(error.message)
    })
}

myDate();