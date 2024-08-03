///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Design of a bill generating class

class Bill {
  // private static variables
  static #prices = {
    Hatchback: {
      BS01: 2000,
      EF01: 5000,
      CF01: 2000,
      BF01: 1000,
      GF01: 3000,
    },
    Sedan: {
      BS01: 4000,
      EF01: 8000,
      CF01: 4000,
      BF01: 1500,
      GF01: 6000,
    },
    SUV: {
      BS01: 5000,
      EF01: 10000,
      CF01: 6000,
      BF01: 2500,
      GF01: 8000,
    },
  };

  static #services = {
    BS01: "Basic Servicing",
    EF01: "Engine Fixing",
    CF01: "Clutch Fixing",
    BF01: "Brake Fixing",
    GF01: "Gear Fixing",
  };

  // private variables
  #car;
  #codes = [];

  constructor(car, ...codes) {
    this.#car = car;
    this.#codes = codes;
  }

  getBill() {
    let car = this.#car;
    let codes = this.#codes;
    let services = Bill.#services;
    let prices = Bill.#prices;

    let bill = {};
    let total = 0;

    for (let i = 0; i < codes.length; i++) {
      let service = services[codes[i]];
      let price = prices[car][codes[i]];
      bill[service] = price;
      total += price;
    }

    bill["Total Bill"] = total;
    bill["Free Complimentary Cleaning"] = total > 10000 ? "Yes" : "No";

    return bill;
  }
}

let bi = new Bill("Sedan", "GF01", "EF01");
let bill = bi.getBill();
console.log(bill);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// func to return sum of digits using promise syntax

let func1 = (a) => {
  let myPromise = new Promise(function (myResolve, myReject) {
    if (Number.isInteger(a)) {
      let sum = 0;
      while (a > 0) {
        let x = a % 10;
        a = Math.trunc(a / 10);
        sum += x;
      }

      myResolve(sum);
    } else {
      myReject("Not a number");
    }

    if (x == 0) {
      myResolve("OK");
    } else {
      myReject("Error");
    }
  });

  myPromise.then(
    function (value) {
      console.log(value);
    },
    function (error) {
      console.log(error);
    }
  );
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// func to flatten any dimension array to a 1D array

let ans = [];

let func = (arr, i) => {
  if (!arr[i]) {
    return;
  }

  if (Number.isInteger(arr[i])) {
    ans.push(arr[i]);
  } else {
    func(arr[i], 0);
  }

  func(arr, i + 1);
};

let arr = [
  [1, 2, 3],
  4,
  [5, 6, 7, [8, 9, 10, [11, 12, 13], 14]],
  [15, 16, 17, 18, 19, [20, 21, 22], [23, 24, 25]],
];

func(arr, 0);

console.log(ans);


/*

What is dependency injection?
Dependency Injection is basically a way of decoupling a class and its dependency, so that the classes do not have to define some common
functions within it, but instead these common methods/services can be defined elsewhere separatel only once and injected (or made available) into the class.
This makes the whole code base of any application more modular and hence easier to manage and debug and also it adheres to the "DRY" (dont repeat yourself) principle.


Explain the difference between REST and GraphQL. When would you choose one over the other?
REST : REST is a simple and most commonly used approach for building apis which uses standard HTTP methods like GET, POST, PUT, DELETE for interacting with an application.
Data is mostly transferred in JSON format in REST and its a stateless approach (meaning that all the info for data exchange should be contained within the request only).
REST apis should be used in most of the cases where not a lot of complex data is needed to be transferred and hence simplicity and ease of implementation is preferred.

GraphQL : it is basically like a query language for apis, using which we can exactly get the data that we want (not much, not less data) in a single request.
GraphQL should be used when complex data structures need to be transffered over the api in a single request. Also when our backend apis need to support
varying clients that require varying data in varying formats from the same api, then GraphQL should be preferred due to its flexibility in providing the exact data in the required structure.


Can you describe the Model-View-Controller (MVC) architecture and its benefits in web development?
MVC architecture allows to separate our whole application into 3 main components : 
1. Model : handels all the database related logic
2. Controller : handels all the internal business logic of the application
3. View : handels the frontend part or the user facing logic of the application
Using MVC allows us to decouple the 3 main parts of our application, which allows them to be individually scaled, developed, tested, deployed and debugged. 


What is the purpose of the Bridge Pattern?
The purpose of bridge pattern is to separate 2 varying entities like for example shape (circle, square) and color (red, yellow) into
abstraction (shape) and implementation (color) and then bridge the abstraction and implementation using composition. Using this we can avoid making new
classes for every new combination of shape and color.


How do you ensure the security of a web application? Give specific examples of techniques or practices you use.
Follwing are some of the techniques that I can think of for web application security purposes:
1. Validation and sanitization of request body coming to backend servers.
2. Implementing some authentication mechanism in the app like for example JWT based authentication or multi-factor-authentication (MFA) if more security is desired.
3. Obtaining a TLS certificate and then configuring our web servers to use HTTPS protocol
4. If we are using SQL based DB, then we should use parametrized queries in our code to prevent sql injection atacks
5. We should try to keep all softwares/resources(like OS, frameworks, libraries, etc.) used by us up-to-date.

How can we achieve data normalization? What are the types of normalization?
Data normalization can be achieved in a relational database by breaking down bigger tables into smaller tables and defining relationships among them, 
so that data redundancy is reduced and hence data integrity is maintained, which in turn allows for efficent CRUD operations on data.
Decomposition of tables can be done based on various normal forms : 
1. First Normal Form (1NF)
2. Second Normal Form (2NF)
3. Third Normal Form (3NF)
4. Boyce-Codd Normal Form (BCNF)
5. Higher normal forms (4NF, 5NF, etc.)


Your customer’s website takes too long to load. What can be the possible reason and solution?
Some of the reasons to why a website might be taking to long to load, and there possible solutions : 
1. Large image, media files : large media files could be minimised using minifying tools and also lazy loading can be implemented on the frontend side
   to load images only when they enter the viewport.
2. Longer load times of media files : CDN can be used to serve static content faster geographically
3. Poor response times of backend apis : The backend can be improved for faster response times by optimising some of the below possible things:
   a. Improving or refactoring poorly written code
   b. Opitmising database queries if possible
   c. implementing caching in both backend and frontend, wherever possible and useful
   d. If too much user traffic is causing the backend servers to slow down then distributed backend servers can be implmented and efficent load balancing
      can be put in place for traffic management


A client requests a feature that requires real-time updates across multiple users. How would you design and implement this feature?
We can integrate our app with any one of the pub/sub services like Google cloud pub/sub, Apache kafka, RabbitMQ, etc.
So basically we can create topics on this pub/sub service and our client/frontend would subscribe to any of the topics that they want.
Then whenever the backend pushes any update on any channel, then the pub/sub service would ensure that the subscribers subscribed to that channel
gets the updates quickly.


You're tasked with integrating a third-party API into your web application. What factors would you consider to ensure seamless integration and maintainable code?
1. Keep the logic of interacting with the third party api separate from the main app logic, so that even if in future the third party api changes
   then wont affect our main app logic and changes would need to be done only in the api logic code.
2. Implement comprehensive error handelling mechanisms in the api code which can handle allkinds of errors like API failure, request timeout, 
   api rate limitting error, etc.
3. Implement logic to not cross the api rate limit and the parallel processing limits of the third party api.


When would you choose Test-Driven Development (TDD) over Behavior-Driven Development (BDD), and vice versa?
TDD should be preffered when we are developing some low-level logic code that needs thorugh testing.
BDD should be preferred when we are developing some user facing features of the app, which would involve communication between non-technical 
and technical members of the team to correctly develop the feature.
Most of the times, both BDD and TDD go hand in hand to develop well-tested and high quality application.


*/