#pragma once
#include <string>
#include "pch.h"
#include "../../BookingSystem/include/pch.h"
#include "../../BLL/include/credentials.h"
#include "../../BLL/include/bookingInfo.h"


using nlohmann::ordered_json;
using json = nlohmann::json;


void insertRecord(std::string username, std::string firstName, std::string lastName, std::string email, std::string password);
bool loginUser(std::string username, std::string email, std::string password);
ordered_json getCitiesData();
bool updateSeatStatusInJson();