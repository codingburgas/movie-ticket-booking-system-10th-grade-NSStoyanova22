#pragma once
#include "pch.h"
#include "../../BLL/include/credentials.h"
#include "../../BLL/include/register.h"
#include "../../DAL/include/files.h"

class Register {
public:
	void display(PageHandler& pages);

private:
	void checkAndInsertCreds();
};