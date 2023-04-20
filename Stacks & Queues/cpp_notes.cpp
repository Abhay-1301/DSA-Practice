// Include the string library
// #include <string>

// Create a string variable
// string greeting = "Hello";

// Output string value
// cout << greeting;



// string myString = "Hello";
// cout << myString[1];
// Outputs e


// string firstName;
// cout << "Type your first name: ";
// cin >> firstName; // get user input from the keyboard
// cout << "Your name is: " << firstName;

// Type your first name: John
// Your name is: John

// However, cin considers a space (whitespace, tabs, etc) as a terminating character, which means that it can only display a single word (even if you type many words):

// Example
// string fullName;
// cout << "Type your full name: ";
// cin >> fullName;
// cout << "Your name is: " << fullName;

// Type your full name: John Doe
// Your name is: John

// From the example above, you would expect the program to print "John Doe", but it only prints "John".

// That's why, when working with strings, we often use the getline() function to read a line of text. It takes cin as the first parameter, and the string variable as second:

// string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// cout << "The length of the txt string is: " << txt.length();