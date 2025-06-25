#include "../include/files.h"

void insertRecord(std::string username, std::string firstName, std::string lastName, std::string email, std::string password)
{
    std::ifstream inFile("../../BookingSystem/Data/accounts.json");
    ordered_json data;
    if (!inFile) {
        std::cout << "Error opening file" << std::endl;
    }
    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> data;
    }
    inFile.close();

    int key = 1;
    while (true) {
        if (!data.contains(std::to_string(key)))
            break;
        key++;
    }

    std::string newKey = std::to_string(key);
    ordered_json newEntry = {
        {"username", username},
        {"firstName", firstName},
        {"lastName", lastName},
        {"email", email},
        {"password", password}
    };
    data[newKey] = newEntry;

    std::ofstream outFile("../../BookingSystem/Data/accounts.json", std::ios::out | std::ios::trunc);
    if (outFile.is_open()) {
        outFile << data.dump(4);
        outFile.close();
        std::cout << "Record inserted successfully." << std::endl;
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

bool loginUser(std::string username, std::string email, std::string password)
{
    std::ifstream inFile("../../BookingSystem/Data/accounts.json");
    ordered_json data;

    if (!inFile) {
        std::cout << "Error opening file" << std::endl;
        return false;
    }

    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> data;
    }
    inFile.close();

    for (auto it = data.begin(); it != data.end(); ++it) {
        ordered_json user = it.value();

        if (user.contains("email") && user["email"] == email && user.contains("username") && user["username"] == username) {
            if (user.contains("password") && user["password"] == password) {
                credentials::firstName = user.value("firstName", "");
                credentials::lastName = user.value("lastName", "");
                return true;
            }
            else {
                std::cout << "Incorrect password." << std::endl;
                return false;
            }
        }
    }

    std::cout << "User not found." << std::endl;
    return false;
}


ordered_json getCitiesData() {
    std::ifstream inFile("../../BookingSystem/Data/cities.json");
    ordered_json data;

    if (!inFile) {
        std::cout << "Error opening file" << std::endl;
        return {};
    }

    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> data;
    }

    inFile.close();
    return data;
}

bool updateSeatStatusInJson() {
    ordered_json data = getCitiesData();
    if (data.empty()) return false;

    for (auto& city : data["cities"]) {
        if (city["name"] == bookingInfo::city) {
            for (auto& cinema : city["cinemas"]) {
                if (cinema["name"] == bookingInfo::cinema) {
                    for (auto& movie : cinema["movies"]) {
                        if (movie["title"] == bookingInfo::movie) {
                            for (auto& projection : movie["projections"]) {
                                if (projection["datetime"] == bookingInfo::projectionDatetime) {
                                    for (auto& seat : projection["seats"]) {
                                        for (const auto& selectedSeat : bookingInfo::selectedSeats) {
                                            if (seat["row"] == selectedSeat.row && seat["col"] == selectedSeat.col) {
                                                seat["taken"] = true;
                                            }
                                        }
                                    }

                                    std::ofstream outFile("../../BookingSystem/Data/cities.json", std::ios::out | std::ios::trunc);
                                    if (outFile.is_open()) {
                                        outFile << data.dump(4);
                                        outFile.close();
                                        return true;
                                    }
                                    else {
                                        return false; 
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false; 
}

bool saveCitiesData(const ordered_json& data) {
    std::ofstream outFile("../../BookingSystem/Data/cities.json", std::ios::out | std::ios::trunc);
    if (outFile.is_open()) {
        outFile << data.dump(4); 
        outFile.close();
        return true;
    }
    std::cout << "Error: Unable to open cities.json for writing.\n";
    return false;
}


bool saveNewBooking() {
    ordered_json bookings = getBookingsData();

    //generate a simple unique id for the booking
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(10000, 99999);
    std::string bookingId = "BK" + std::to_string(distrib(gen));

    ordered_json newBooking = {
        {"user_email", credentials::email},
        {"movie_title", bookingInfo::movie},
        {"cinema_name", bookingInfo::cinema},
        {"city_name", bookingInfo::city},
        {"projection_datetime", bookingInfo::projectionDatetime},
        {"hall", bookingInfo::hall},
        {"total_cost", bookingInfo::totalCost},
        {"seats", json::array()}
    };

    for (const auto& seat : bookingInfo::selectedSeats) {
        newBooking["seats"].push_back({
            {"row", seat.row},
            {"col", seat.col},
            {"type", seat.type},
            {"price", seat.price}
            });
    }

    bookings[bookingId] = newBooking;

    return saveBookingsData(bookings);
}

//get all data from bookings.json
ordered_json getBookingsData() {
    std::ifstream inFile("../../BookingSystem/Data/bookings.json");
    ordered_json data;
    if (inFile.is_open()) {
        if (inFile.peek() != std::ifstream::traits_type::eof()) {
            inFile >> data;
        }
        inFile.close();
    }
    return data;
}

//save data back to bookings.json
bool saveBookingsData(const ordered_json& data) {
    std::ofstream outFile("../../BookingSystem/Data/bookings.json", std::ios::out | std::ios::trunc);
    if (outFile.is_open()) {
        outFile << data.dump(4);
        outFile.close();
        return true;
    }
    return false;
}
