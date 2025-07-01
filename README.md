[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/LIdE0kg1)
# 2223-10: On the job training (OTJ) project

# Movie Ticket booking system
This document describes the OTJ project for 10th graders. **It will be updated frequently**.

# 1. Assignment Goals
The movie ticket booking system is a system that allows customers to book shows for their favorite movies. The booking system has information on all cinemas present in different cities and the hall information for each cinema. There are numerous movies stored in the system database. Each movie can have multiple shows playing in a particular cinema. The customer can search and select a movie for which they wish to book a show. The system displays a seating layout that identifies booked and available seats so that the customer can choose to reserve available seats. Once the customer completes the payment for the booking, the seat booking is confirmed and the customer receives an email notification.

# 2. Expectations from the interviewee
Numerous components are present in a typical movie ticket booking system, each with specific constraints and requirements placed on them. The following provides an overview of some of the main expectations that the interviewer will want to hear you discuss in more detail during the interview.

## 2.1. Seat selection
Selecting a seat is an essential part of the movie ticket booking system. The system has to make sure that no two people can book the same seat. The interviewer expects you to ask questions to identify how the system will work in these situations:

* How will the system make sure that multiple users do not book the same seat?
* Will there be a timeout session that reserves seats temporarily? Will the system use a first come, first serve algorithm?
* Will there be transaction locks involved in the system?

## 2.2. Payment handling
One of the most significant attributes of the movie ticket booking system is the payment structure that it provides to its customers. This can vary, so the interviewer would expect you to ask the questions listed below:

* What payment methods can the customer use (for example, credit card or cash)?
* How is the payment performed? Does the customer pay themselves online or through a ticket agent on the location?

## 2.3. Price variance
We touched upon the payment methods of the movie ticket booking system, now, the pricing model needs to be clarified by the interviewer, and therefore you may ask questions like these:
* How will the price of the booking be calculated? Will it vary based on the popularity of the show?
* Does the seat type affect the pricing?
* Will there be discount coupon codes?

## 2.4. Duplication
There will be many duplicate instances in our system. The interviewer expects you to ask questions like these:
* How are we handling these instances, such as the same cinema having multiple cinema halls showing different movies simultaneously?
* Is the same movie being shown at different times in the same cinema/hall?

# 3. Requirements for the Movie Ticket Booking System
The following are the requirements that we have defined for the movie ticket booking problem:

### Stage One
* R1: There exist multiple cinemas in the city, and the cinema has multiple halls.

* R2: Each movie in the cinema can have multiple shows, however, one hall will only show one show at a time.

* R3: The cinema displays all available showtimes of a movie.

* R4: Users can search movies based on the following four criteria: title, language, genre, and release date.

### Stage Two
* R5: Users can make a booking at any cinema hall at the available showtime.

* R6: The booking can either be made by the customer online or via a walk-in by the ticket agent.

* R7: Online customers can only pay using a credit card, while walk-in customers can pay using cash or credit card through the ticket agent.

### Stage Three
* R8: Users can select multiple available seats for a show from a given seating arrangement.

* R9: Each seat type has a fixed cost. There are three types of seats: silver, gold, and platinum.

* R10: There can only be one ticket allocated per seat.

* R11: No two customers should be able to reserve the same seat.

### Stage Four
* R12: The admin can perform the following five actions on the show times and the movie:

    * Add a show
    * Delete a show
    * Update a show
    * Add a movie
    * Delete a movie

* R13: The system should be able to differentiate between available and booked seats.

### Stage Five
* R14: The system should generate a notification for the following three cases:

    * A new movie has been released.
    * A booking has been made.
    * A booking has been canceled.

# Base requirements

* Programming language: C++
* Visual Studio 2022 (latest release)
* Git for Windows (latest release)
* Skill for working with Git from command line (CLI) & Git extension in Visual Studio
* Following the best practices for C++ / Git / GitHub is a mandatory requirement

Additional requirements will be added later.



<h1 align="center"><b>🎬 Movie Ticket System App 🎟️</b></h1>

<div align="center">
    <p>⭐ Pick a movie | 🍿 Choose your seat | 🎞️ Enjoy the show!</p>
</div>

---

# 📋 About
This is my movie ticket booking app — built entirely in C++ and running in the console. With it, you can browse movies, pick a city and cinema, choose your showtime, and book your seats easily. There's also an admin mode where you can add new movies, projections, and manage bookings. I made this project as part of my final assignment — hope you like it! 

# ✨ Features
### For Customers
* **Login & Register:** You can make your own account and log in.
* **Book a Ticket:** A full flow from picking a city and cinema to choosing your seat.
* **Browse Program:** You can look at all movies and showtimes for a cinema without booking.
* **Search Movies:** You can search for movies by title, genre, language, or release date.
* **Seat Selection:** A map shows you which seats are free, taken, or reserved.
* **View & Cancel Bookings:** You can see your booking history and cancel tickets.

### For Admins
* **Admin Panel:** A special menu for admins to manage the system.
* **Manage Movies:** Admins can add new movies to a cinema or delete them.
* **Manage Shows:** Admins can add, delete, or update showtimes for any movie.

# 🛠️ How to Run
1. 📥 Clone the project using the "Code" button or run this in git bash:
```bash
git clone https://github.com/codingburgas/movie-ticket-booking-system-10th-grade-NSStoyanova22.git
```
<br>
2. 📂 Open `BookingSystem.sln` in Visual Studio 2022. <br><br>
3. ▶️ Set `BookingSystem` as the StartUp Project and press F5 to run.

# 💻 Languages and Tools
<div align="left">
  <img width="40" height="40" src="https://img.icons8.com/?size=100&id=40669&format=png&color=000000" alt="C++">
  <img width="40" height="40" src="https://img.icons8.com/?size=100&id=20931&format=png&color=000000" alt="Visual Studio">
  <img width="40" height="40" src="https://img.icons8.com/?size=100&id=13331&format=png&color=000000" alt="JSON">
</div>

# 📁 Project Documents
<ul>
    <li><a href="https://codingburgas-my.sharepoint.com/:w:/r/personal/nsstoyanova22_codingburgas_bg/_layouts/15/Doc.aspx?sourcedoc=%7B17D307D4-7269-4C39-B620-B4D7C788B80F%7D&file=Documentation%20(1).docx&action=default&mobileredirect=true&wdOrigin=SEARCHENGINE.GOOGLE%2CAPPHOME-WEB.BANNER.UPLOAD&wdPreviousSession=fe64652a-929a-44f3-b0e1-c27f37180bf6&wdPreviousSessionSrc=AppHomeWeb&ct=1751311596947">Documentation</a></li>
    <li><a href="https://codingburgas-my.sharepoint.com/:p:/r/personal/nsstoyanova22_codingburgas_bg/_layouts/15/Doc.aspx?sourcedoc=%7B72DAF7C2-8B29-434C-8930-7A00E8FDB58E%7D&file=movieBookingPresentation%202.pptx&action=edit&mobileredirect=true">Presentation</a></li>
</ul>


<br>
<div align="center">
<pre>
      .--.
     |o_o |
     |:_/ |
    //   \ \
   (|     | )
  /'\_   _/`\
  \___)=(___/
</pre>
</div>
<h2 align="center">
 If you like my app, please give a 🌟 to the repository!
</h2>
