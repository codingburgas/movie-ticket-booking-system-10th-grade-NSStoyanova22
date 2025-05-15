#pragma once
#include "pch.h"
#include "../../BLL/include/credentials.h"
#include "../../BLL/include/register.h"
#include "../../DAL/include/files.h"

class Login {
public:
	void display();
	void inputCreds();
	void checkCreds();
};