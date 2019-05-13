var weather = false
var date    = new Promise(function(resolve, reject) {
  if (weather) {
    var dateDetails = {
      name:     'XYZ Restaurant',
      location: 'Hyd',
    };

    resolve(dateDetails)
  } else {
    reject(new Error('Bad weather, so no Date'))
  }
});



var myDate = function() {
  date
    .then(function(done) {
      console.log('We are going on a date!')
      console.log(done)
    })
    .catch(function(error) {
        console.log(error.message)
    })
}

myDate();