console.log("start");

setTimeout(() => {
  console.log("hello from setTimeout");
}, 0);

async function callFromWebApi() {
  console.log("inside async");
  const repsonse = await fetch("https://jsonplaceholder.typicode.com/todos/2");
  const data = await repsonse.json();
  console.log("after  async operation");
  console.log(data);
}

callFromWebApi();
console.log("end");
