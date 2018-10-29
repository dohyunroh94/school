// proj1.js
// Description:
// Javascript file for proj1.
// Contains functions for drawing a clock as well
// as inputing numbers to guess clock times 
// and inputting student names into a list.
// The user add student names
// into a list, log in with a name, keep 
// track of how well students are doing,
// and remove specific students from list.



// SETUP variables

// Sets up canvas to draw clock.
// Sets the center draw position
// as the center of the canvas with rad, rad.
// Sets to 0.9 so the circle doesn't take up
// whole canvas frame.
// Draws the clock with functions
var canvas = document.getElementById("myCanvas");
var ctxt = canvas.getContext("2d");
var rad = (canvas.height / 2);
ctxt.translate(rad, rad);
rad = rad * 0.9;

// Sets up the arrays for list of students, 
// number of correct and wrong answers
// for each student. Also, keeps trach of
// current user.
// Needs to be accessible for many functions
// so declared outside functions.
var students = [];
var correct = [];
var wrong = [];
var currentUser;
var passcode = "tellingtime";

// Sets up clockFace 
// and universal time variable 
// that represents current time 
// displayed.
makeClock();
var time = null;

// Takes the clock face without hands data and saves it
// so we can go back and put a different time onto the face.
var noHandsFace = ctxt.getImageData(0, 0, canvas.width, canvas.height);

// Sets up the clock with random hands
time = randomTimeDraw();




// GENERAL FUNCTIONS FOR INTERACTING WITH USER INPUT

// Erases the previous clock hand positions
// and draws new random hands.
// Returns the time as well (as an array)
function showTime(){
	
	ctxt.putImageData(noHandsFace, 0, 0);
	var time = randomTimeDraw();
	return time;
	
}

// Asks user (if logged in) for 
// the time of the shown clock.
// If correct, the user's correct score value get 
// incremented. (correct[]) If incorrect, the user's 
// wrong score value (wrong[]) gets incremented.
function play(t_time){
		
	// Checks if someone is logged in.
	if (currentUser){ 
			
		// Gets the calculated random time (array of hour and minute value);
		var actualHour = t_time[0];
		var actualMin = t_time[1];
	
		// Asks for hour and minute
		// values from user
		var hour = prompt("What hour is it?", "");
		var min = prompt("How many minutes is it?", "");
		
	
		// Checks make sure values are valid (not null or empty)
		if (hour && min){
	
			hour = parseInt(hour);
			min = parseInt(min);
	
			// If all correct
			if ((hour == actualHour) && (min == actualMin)){

				alert("Great job!");
				correct[findStudent(currentUser)] += 1;
				
		
			// If either hour or minute, or both values are wrong
			} else {

				alert("Wrong. Try again!");
				wrong[findStudent(currentUser)] += 1;
		
			}
		
		
			// Calcultes score and displays
			// a postive or negative message 
			// depending on performance
			var score =  (correct[findStudent(currentUser)] / 
			(correct[findStudent(currentUser)] + wrong[findStudent(currentUser)]));
			
			// For 95% and up
			if (score > 0.95){
				
				document.getElementById('user').innerHTML = currentUser + " is doing fantastic! :)";
			
			// For 85% and up
			} else if (score > 0.85){
				
				document.getElementById('user').innerHTML = currentUser + " is doing pretty well! :)";
			
			// For 70% and up
			} else if (score > 0.70){
				
				document.getElementById('user').innerHTML = currentUser + " is doing okay!";
				
			// Anything below 70%
			} else {
				
				document.getElementById('user').innerHTML = currentUser + " could use more practice! :(";
			
			}
				
			// Changes the clock time to a new time after
			// a try 
			time = showTime();
		
		// If inputed values are empty spaces
		} else if ((hour != null) && (min != null)){
			
			alert("Please enter a number");
			
		}
		
	// When no one is logged in 
	} else {
			
		alert("No one is logged in! To play, log in!");
			
	} 

}		
	

	// Prompts user to type in first name
	// and last name.
	// If name isn't empty, the name is inserted into
	// the list of students. Displays that the name 
	// has been entered. 
	function addStudent(){
		
		// Asks for name.
		var name = prompt("Enter the student's first and last name(Eg: 'Mark Smith'): ", "");
			
		// If name is valid (not empty or null)
		// and was not found in student list
		if (name && (findStudent(name) == -1)){
		
			// Adds name to student list 
			// and creates correct and wrong scores
			students[students.length] = name;
			correct[correct.length] = 0;
			wrong[wrong.length] = 0;
			
			alert(name + " has been entered.");
			
		// If the name has already been inputted 
		} else if (findStudent(name) >= 0){
		
			alert("That name has already been used. Please enter a different name!"); 
			alert("For same names, adding a number to the name is recommended. (Eg: 'Steve1 Smith, Steve2 Smith')");
		
		// If name is empty.
		// (Pressing cancel induces null value, so this would
		// alert only invalid input and skips null)
		} else if (name != null){
				
			alert("Please enter a name!");
			
	} 
}

// Removes a student from the 
// student list by prompting the user
// for a name, and matching the name
// in the student array. If 
// not found, then says to user
// that the name cannot be found.
// It is password protected, so
// a password must be inputted
function removeStudent(){
	
	// Asks for password
	var pass = prompt("Enter your password", "")
	
	// Checks for cancel (induces null value)
	if (pass != null) {
	
		// Checks if password is correct
		if (pass == passcode){
	
			// If there are students in list 
			if (students.length > 0){
				
				// Prompts user for full name 
				var name = prompt("Enter both first and last name(Eg: 'Mark Smith'): ", "");
				
				// If name is valid (not empty or null)
				if (name){
			
					var index = findStudent(name);
					
					// Checks name index was found 
					if (index >= 0) {
						
						// Removes student and score data
						// from students, correct, and wrong arrays
						// (They all share corresponding index values)
						students.splice(index, (index + 1));
						correct.splice(index, (index + 1));
						wrong.splice(index, (index + 1));
						
						// Checks if current user is removed student.
						if (currentUser == name){
							
							currentUser = "";
							document.getElementById('user').innerHTML = "No one is playing right now :(";
							
						}
						
						alert(name + " was removed. Sorry to see you go :(");
					
					// If name isn't in the list 
					} else {
				
						alert("No student with the name " + name + " was found.");

					}
			
				// If a blank name is entered
				// (note that checking for !null
				// makes it so user can exit without
				// being prompted)
				} else if (name != null){
					
					alert("Please enter a name.");
					
				}

			// When the student array is empty
			} else {
				
				alert("There are no students added in the list!");
				
			}
			
		// If password is incorrect	
		} else {
			
			alert("The password you have entered is incorrect. Please try again.");
			
		}
	}
}

// Views all students and each of their scores
// displayed in a separate window. 
function viewStudents(){
	
	// Asks for password
	var pass = prompt("Enter your password: ","");
	
	// If user didn't press cancel (which induces a null value)
	if (pass != null){ 
	
		if (pass == passcode){
		
			// Opens a separate window for the student data
			var studentList = window.open("", "List Of Students", "width = 400, height = 400");
	
			// Will display in window that no students are added if 
			// there is an empty array
			if (students.length == 0 ){
		
				studentList.document.open();
				studentList.document.write("No students have been entered." + "<br/>");
				studentList.document.close();
		
			// Writes the table into the popup window document
			// when there is student data
			} else {
		
				// Writes the css style sheet link here
				// for the window to access. 
				studentList.document.open();
				studentList.document.write("<head><link rel='stylesheet' href='proj1.css'></head>");
				studentList.document.write("<table>");
				studentList.document.write("<tr><th>Name</th><th>Number of correct answers</th><th>Number of incorrect answers</th><th>Score</th></tr>");
			
				// Writes the student name, number of correct, number of incorrect, and correct percentage 
				// for each row in the table
				var index;
				var percent = 0;
				for (index = 0; index < students.length; index++){
			
					percent = 0;
			
					// Calculates correct percentage
					// and gets rid of remaining decimal.
					// Only calculates if there's actually a score.
					// (For 0 percent to show properly)
					if ((correct[index] + correct[index]) != 0){ 
						percent = correct[index]/(correct[index] + wrong[index]);
					}
					
					percent = percent * 100;
					percent = Math.floor(percent);
					studentList.document.write("<tr><td>" + students[index] +"</td><td>" + correct[index] + "</td><td>"+ wrong[index] +
					"</td><td>" + percent + "%" + "</td></tr>");
			
				}
		
				// Ends table 
				studentList.document.write("</table>");
				studentList.document.close();
		
			}
		
		// Wrong password
		} else {
		
			alert("The password you have entered is incorrect. Please try again.");
		
		}
	
	}
	
}

// Asks a student in the list to log in 
// as the current user.
function logIn(){
	
	// If there are no students in the list.
	if (students.length == 0){
		
		alert("There are no students entered! Add a student!");
    
	// Asks for name to log in.
	} else {
		
		var name = prompt("What is your name? (First and last name)", "");
		
		// If name isn't empty or null
		if (name){
		
			// If name is in the students array
			if (findStudent(name) >= 0){
				
				// Sets the name to current user and 
				// displays the her or she is playing currently 
				currentUser = name;
				document.getElementById('user').innerHTML = name + " is playing right now! :)";
				alert("Hello " + name + "!");
			
			// If name cannot be found
			} else {
				
				alert("Student not found in the list.");
				
			}
		
		}
	
	}
	
}

// Searches through the student array to find 
// a specific student and returns the position.
// Returns -1 if not found.
function findStudent(name){
	
	var studentName;
	for (index = 0; index < (students.length); index++){
		
		studentName = students[index];
		if (name == studentName){
			
			return index;
			
		}
		
	}
	
	return -1;
	
}




// DRAWING CLOCK FUNCTIONS 

// Makes the whole clock, including face and hands.
function makeClock(){
	
	drawClockFace();
	
}

// Draws just clock face without hands
function drawClockFace(){

	// Fills a circle with white color within
	// the canvas
	ctxt.beginPath();
	ctxt.arc(0, 0, rad, 0, (2 * Math.PI));
	ctxt.fillStyle = 'white';
	ctxt.fill();
	
	// Creates a border for the circle
	var grad;
	grad = ctxt.createRadialGradient(0, 0, rad * 0.95, 0, 0, rad * 1.05);
	grad.addColorStop(0, 'black');
	ctxt.strokeStyle = grad;
	ctxt.lineWidth = rad * 0.11;
	ctxt.stroke();
	
	// Creates a circle inside the circle 
	// (Center for holding the clock hands)
	ctxt.beginPath();
	ctxt.arc(0, 0, rad * .05, 0, 2 * Math.PI);
	ctxt.fillStyle = "black"
	ctxt.fill();
	
	// Creates numbers
	var angle;
	var number;
	ctxt.font = rad * .15 + "px times new roman";
	ctxt.textBaseline="middle";
    ctxt.textAlign="center";
	
	// For each number, starts at center (original start pos)
	// rotates by the proper angle for each number
	// (multiplies number by (pi/6) or 30 degrees
	// tranlates up to 85% of radius, reverses rotation
	// (no tilt), and writes number
	// Afterwards, sets the position back to center
	for (number = 1; number < 13; number++){
		
		
		angle = number * (Math.PI / 6);
		ctxt.rotate(angle);
		ctxt.translate(0, -rad * 0.85);
		ctxt.rotate(-angle);
		ctxt.fillText(number.toString(), 0, 0);
		ctxt.rotate(angle);
		ctxt.translate(0, rad * 0.85);
		ctxt.rotate(-angle);
		
		
		
	}
	
	// Sets up tick marks.
	// Rotates by 6 degrees
	// goes to the proper position
	// (slightly above number) and
	// writes a '|' as tick mark.
	// It translates and rotates back 
	// to the original center position.
	// Does this for 60 tick positions.
	var tick;
	for (tick = 1; tick <= 60; tick++){
		
		angle = (Math.PI / 30) * tick;
		ctxt.rotate(angle);
		
		// Sets tick marks for hours
		// longer.
		if ((tick % 5) == 0){
		
			ctxt.translate(0, -rad * .97);
			ctxt.fillText('|', 0, 0);
			ctxt.translate(0, rad * .97);
			
		// Sets rest of the tick marks to be 
		// shorter.
		} else { 		
			
			ctxt.translate(0, -rad);
			ctxt.fillText('|', 0, 0);
			ctxt.translate(0, rad);
			
		
		}
		
		ctxt.rotate(-angle);
		
	}
	
}

// Sets up random times for the 
// hands to be positioned in, than
// draws the hands in positions.
function randomTimeDraw(){
		
	// Random numbers for all time values
	var hour = Math.floor((Math.random() * 12) + 1);
	var minute = Math.floor(Math.random() * 60);
	var second = Math.floor(Math.random() * 60);
	
	var time = [hour, minute];
		
	// Sets up the appropriate angles for each
	// time unit. The hour hand depends on hour, 
	// minute, and second values while minute 
	// depends on minute and second values. 
		
	// Hour has to be modulo-divided 
	// (for 12 to be 0 degrees).
	// Hour's angle depends on hour, minute, and second values.
	// Draws the hour hand. 
	hour = hour % 12; 
	hour = (hour * Math.PI / 6) + 
	(minute * Math.PI/ (6 * 60)) +
	(second * Math.PI/(6 * 60 * 60));
	handDraw(ctxt, hour, (rad * 0.5), (rad * 0.05));
		
	// Minute's hand only depends on minute value
	// (For easier reading on which minute it's on).
	// Draws the minute hand
	minute = (minute * Math.PI / 30);
	handDraw(ctxt, minute, (rad * 0.85), (rad * 0.05));
		
	return time;
}
	
// Draws a hand of a clock.
// Can choose the angle (pos), width, and 
// length.
function handDraw(ctxt, pos, len, width){
	

	// Starts the drawing. 
	// Sets the width and 
	// square ends.
	ctxt.beginPath();
	ctxt.lineWidth = width;
	ctxt.lineCap = "square";
	
	// Moves drawing position to 
	// center of circle.
	// Rotates by the angle (pos)
	// and draws line to appropriate
	// position (it's -len because from
	// (0,0), (0, -len) is actually going up)
	// Finishes draw by stroke() and rotates
	// position back to (0,0) or center.
	
	ctxt.moveTo(0,0);
	ctxt.rotate(pos);
	ctxt.lineTo(0, -len);
	ctxt.stroke();
	ctxt.rotate(-pos);
				
}



	
	



