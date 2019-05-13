function myArray(arr , i)
{ 
	function sum(){
		if(!Array.isArray(arr)) 
			return;
	  	return arr.reduce((a, v)=>a + v);
	}

	function pro(){
		if(!Array.isArray(arr)) 
			return;
	  	return arr.reduce((a, v)=>a * v);

	}

	function sort(){
		return arr.sort();
	}

	function modify(i){
		arr[i] += 1;
	}

	function display(){
		var len = arr.length;
		for(int i = 0 ; i<n ; i++){
			console.log(arr[i]);
		}
	}

	var obj = {};
	obj["sum"] = sum();
	obj["pro"] = pro();
	obj["sort"] = sort();
	obj["modify"] = modify(2);
	obj["display"] = display();

	return obj;
}



arr = [1,2,3,5,3,2];

