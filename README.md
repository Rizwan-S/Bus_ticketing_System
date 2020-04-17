# Inter-city bus ticketing system:
This project was created to facilitate easy booking of bus tickets for inter city travel.

It incorporates the following features:

## Customer Features:

1) Display all buses:

This feature enables the user to view all the buses available for travel along with the bus type and time duration of travel.

2) Display all cities:

This feature enables the user to view all the cities between which the buses ply.

3) Display buses based on start city:

This feature enables the user to view all the buses which have their departure from the entered city.

4) Display all buses based on destination city:

This feature enables the user to view all the buses which have their destination city as the entered city.

5) Book ticket:

Ticket booking:

This feature enables the user to make a booking for bus tickets between the cities which they wish to based on the dates entered.The user will be able to view the buses available based on the cities which they have entered and make a booking based on the availability of seats on the bus.

Pricing:

A unique feature added is the pricing where the pricing is dynamic to a basic level.This means that the pricing is done with respect to various factors.To incorporate a more dynamic mode of pricing the project incorporates script to frame an integer calendar which also has a flagged system for holidays and working days.The increase in demand for travel during holidays is managed by surge in prices nearing the holidays. Also the closer the booking date is to the current date the higher the prices will be for the customer.In this way pricing as a whole has been made dynamic. As a future improvement to the pricing function we will be able to run scripts which will read holidays at will and then update the calendar.

6) Cancel Ticket:

This feature enables the user to cancel a ticket that has been booked.The status of the booking for all the seats will be displayed and the status of the seats after cancellation will also be displayed.

## Admin Features:

The next two features have been included keeping future improvements to the projects in close proximity.In the future there will also be a login which differentiates between an admin and a user.

7) Add a bus:

This is a feature for the admin.The admin will be able to add a new bus between two cities along with all the necessary information that needs to be stored.

8) Delete a bus:

This is also an admin feature, where the admin will be able to remove an existing bus between the two cities he wants based on the bus number.

9) Quit the program:

This feature enables the user to quit the program if he wishes to do so.

## Creation of the Project:

The project has been made completely only using C Language and the various features it provides.

## Execution of the project:

Run the following commands in terminal
	
	make	
	./a.out

### Enjoy the ticket booking system.

Team Members:

Divyam Agrawal , 
Neelabh P Bhaskar , 
Nidhish Bhimrajka , 
Komma Yashovardhan Reddy , 
Shivyansh Garg , 
Rizwan Shaikh 
