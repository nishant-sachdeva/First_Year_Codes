var string = "  HEllo world to you too say hi  "
var str = string.trim();

var arr = new Array
arr = [..str];

for(var i = 0 , j = 1 ; i<arr.length; i++)
{
		if(arr[i] == ' ')
		{
				if(j%2 == 0)
						arr[i] = '_';
				j++;
		}
}
// here our array is ready;
s = arr.join('');
console.log(s);

