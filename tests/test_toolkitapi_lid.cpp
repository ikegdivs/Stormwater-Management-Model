// NOTE: Travis installs libboost test version 1.5.4
//#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE "toolkitAPI_lid"
#include "test_toolkitapi_lid.hpp"
#include <vector>

using namespace std;

// Non-Fixuture Unit Tests
BOOST_AUTO_TEST_SUITE(test_lid_toolkitapi)

    // Test Model Not Open
    BOOST_AUTO_TEST_CASE(model_not_open)
    {
        int error;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        //Lid Control
        error = swmm_getLidCOverflow(0, &chr_value);
        BOOST_CHECK_EQUAL(error, 502);
        error = swmm_getLidCParam(0, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 502);
        error = swmm_setLidCParam(0, 0, 0, db_value);
        BOOST_CHECK_EQUAL(error, 502);

        //Lid Unit
        error = swmm_getLidUCount(0, &int_value);
        BOOST_CHECK_EQUAL(error, 502);
        error = swmm_getLidUParam(0, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 502);
        error = swmm_setLidUParam(0, 0, 0, db_value);
        BOOST_CHECK_EQUAL(error, 502);
        error = swmm_getLidUOption(0, 0, 0, &int_value);
        BOOST_CHECK_EQUAL(error, 502);
        error = swmm_setLidUOption(0, 0, 0, int_value);
        BOOST_CHECK_EQUAL(error, 502);
        error = swmm_getLidUFluxRates(0, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 502);
        error = swmm_getLidUResult(0, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 502);

        //Lid Group
        error = swmm_getLidGResult(0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 502);
    }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(test_lid_toolkitapi_fixture)

    // Testing for Simulation Started Error
    BOOST_FIXTURE_TEST_CASE(sim_started_check, FixtureBeforeStep_LID)
    {
        open_swmm_model(0);
        int error;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        //Lid Control
        error = swmm_getLidCOverflow(0, &chr_value);
        BOOST_CHECK_EQUAL(error, 0);
        error = swmm_getLidCParam(0, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 0);
        error = swmm_setLidCParam(0, 0, 0, db_value);
        BOOST_CHECK_EQUAL(error, 0);

        //Lid Unit
        error = swmm_getLidUCount(0, &int_value);
        BOOST_CHECK_EQUAL(error, 0);
        error = swmm_getLidUParam(0, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 0);
        error = swmm_setLidUParam(0, 0, 0, db_value);
        BOOST_CHECK_EQUAL(error, 503);
        error = swmm_getLidUOption(0, 0, 0, &int_value);
        BOOST_CHECK_EQUAL(error, 0);
        error = swmm_setLidUOption(0, 0, 0, int_value);
        BOOST_CHECK_EQUAL(error, 503);
        error = swmm_getLidUFluxRates(0, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 0);
        error = swmm_getLidUResult(0, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 0);

        //Lid Group
        error = swmm_getLidGResult(0, 14, &db_value);
        BOOST_CHECK_EQUAL(error, 0);
    }


    // Testing for invalid object index
    BOOST_FIXTURE_TEST_CASE(object_bounds_check, FixtureOpenClose_LID)
    {
        open_swmm_model(0);
        int error;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        //Lid Control
        error = swmm_getLidCOverflow(1, &chr_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_getLidCParam(1, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_setLidCParam(1, 0, 0, db_value);
        BOOST_CHECK_EQUAL(error, 505);

        //Lid Unit
        error = swmm_getLidUCount(2, &int_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_getLidUParam(2, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_setLidUParam(2, 0, 0, db_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_getLidUOption(2, 0, 0, &int_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_setLidUOption(2, 0, 0, int_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_getLidUFluxRates(2, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_getLidUResult(2, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 505);

        //Lid Group
        error = swmm_getLidGResult(2, 14, &db_value);
        BOOST_CHECK_EQUAL(error, 505);
    }

    // Testing for invalid parameter key
    BOOST_FIXTURE_TEST_CASE(key_bounds_check, FixtureOpenClose_LID)
    {
        open_swmm_model(0);
        int error;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        //Lid Control
        error = swmm_getLidCParam(0, 0, 100, &db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_setLidCParam(0, 0, 100, db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_getLidCParam(0, 100, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_setLidCParam(0, 100, 0, db_value);
        BOOST_CHECK_EQUAL(error, 501);

        //Lid Unit
        error = swmm_getLidUParam(0, 0, 100, &db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_setLidUParam(0, 0, 100, db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_getLidUOption(0, 0, 100, &int_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_setLidUOption(0, 0, 100, int_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_getLidUFluxRates(0, 0, 100, &db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_getLidUResult(0, 0, 100, &db_value);
        BOOST_CHECK_EQUAL(error, 501);

        //Lid Group
        error = swmm_getLidGResult(0, 100, &db_value);
        BOOST_CHECK_EQUAL(error, 501);
    }

    // Testing for undefined lid usage
    BOOST_FIXTURE_TEST_CASE(undefined_lid_check, FixtureOpenClose_LID)
    {
        open_swmm_model(0);
        int error;
        double db_value = 0;

        //Lid Unit
        error = swmm_getLidUResult(0, 1, SM_INFLOW, &db_value);
        BOOST_CHECK_EQUAL(error, 511);
        error = swmm_getLidUFluxRates(0, 1, SM_SURFACE, &db_value);
        BOOST_CHECK_EQUAL(error, 511);

        //Lid Group
        error = swmm_getLidGResult(1, 14, &db_value);
        BOOST_CHECK_EQUAL(error, 511);
    }

    // Testing for Project Settings after Open
    BOOST_FIXTURE_TEST_CASE(project_lid_info, FixtureOpenClose_LID)
    {
        open_swmm_model(0);
        int error, index, sub_index, int_value;

        string id = string("BC");
        string subcatch = string("wBC");

        sub_index = swmm_getObjectIndex(SM_SUBCATCH, (char *)subcatch.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        //Project
        index = swmm_getObjectIndex(SM_LID, (char *)id.c_str(), &error);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(index, 0);

        error = swmm_getLidUCount(sub_index, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);
    }

    // Testing for Lid Control Bio Cell parameters get/set
    BOOST_FIXTURE_TEST_CASE(getset_lidcontrol_BC, FixtureOpenClose_LID)
    {
        open_swmm_model(0);
        int error, lid_index, sub_index;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        string bioCell = string("BC");
        string subcatch = string("wBC");

        lid_index = swmm_getObjectIndex(SM_LID, (char *)bioCell.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        sub_index = swmm_getObjectIndex(SM_SUBCATCH, (char *)subcatch.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        // Lid Control
        // Surface layer get/set check
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.25, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, 0.9);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.9, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0.2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ALPHA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.05359, 0.0001);

        // Soil layer get/set
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 12, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_POROSITY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_POROSITY, 0.3);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_POROSITY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.3, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_FIELDCAP, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_FIELDCAP, 0.3);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_FIELDCAP, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.3, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_WILTPOINT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_WILTPOINT, 0.3);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_WILTPOINT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.3, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_KSAT, 0.1);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 10, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_KSLOPE, 20);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 20, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_SUCTION, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 3.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_SUCTION, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_SUCTION, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        // Storage layer get/set check
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 12, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, 0.15);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.15, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_KSAT, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        // Drain layer get/set
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_COEFF, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_COEFF, 1.0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_COEFF, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.0, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_EXPON, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_EXPON, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_EXPON, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_OFFSET, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_OFFSET, 20);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_OFFSET, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 20, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_DELAY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_DELAY, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_DELAY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HOPEN, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_HOPEN, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HOPEN, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        // Check for immediate overflow option
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 0);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 1);

        // Lid Unit
        error = swmm_getLidUCount(sub_index, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);

        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 50, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_UNITAREA, 1000);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1000, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 10, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FWIDTH, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_INITSAT, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 25, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FROMIMPERV, 75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 75, 0.0001);

        error = swmm_getLidUOption(sub_index, 0, SM_INDEX, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, lid_index);

        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 100);
        error = swmm_setLidUOption(sub_index, 0, SM_NUMBER, 11);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 11);

        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);
        error = swmm_setLidUOption(sub_index, 0, SM_TOPERV, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINSUB, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINNODE, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);
    }

    // Testing for Lid Control Green Roof parameters get/set
    BOOST_FIXTURE_TEST_CASE(getset_lidcontrol_GR, FixtureOpenClose_LID)
    {
        open_swmm_model(1);
        int error, lid_index, sub_index;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        string greenRoof = string("GR");
        string subcatch = string("wGR");

        lid_index = swmm_getObjectIndex(SM_LID, (char *)greenRoof.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        sub_index = swmm_getObjectIndex(SM_SUBCATCH, (char *)subcatch.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        // Surface layer get/set check
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.25, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, 0.9);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.9, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0.2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ALPHA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.05359, 0.0001);

        // Soil layer get/set
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 12, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_POROSITY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_POROSITY, 0.3);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_POROSITY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.3, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_FIELDCAP, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_FIELDCAP, 0.3);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_FIELDCAP, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.3, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_WILTPOINT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_WILTPOINT, 0.3);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_WILTPOINT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.3, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_KSAT, 0.1);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 10, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_KSLOPE, 20);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 20, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_SUCTION, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 3.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_SUCTION, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_SUCTION, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        // Drainmat layer get/set
        error = swmm_getLidCParam(lid_index, SM_DRAINMAT, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 3, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAINMAT, SM_THICKNESS, 11);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAINMAT, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 11, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAINMAT, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAINMAT, SM_VOIDFRAC, 0.1);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAINMAT, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAINMAT, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAINMAT, SM_ROUGHNESS, 0.2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAINMAT, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAINMAT, SM_ALPHA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.05359 - 0, 0.0001);

        // Check for immediate overflow option
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 0);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 1);

        // Lid Unit
        error = swmm_getLidUCount(sub_index, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);

        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 50, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_UNITAREA, 1000);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1000, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 10, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FWIDTH, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_INITSAT, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 25, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FROMIMPERV, 75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 75, 0.0001);

        error = swmm_getLidUOption(sub_index, 0, SM_INDEX, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, lid_index);

        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 100);
        error = swmm_setLidUOption(sub_index, 0, SM_NUMBER, 11);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 11);

        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);
        error = swmm_setLidUOption(sub_index, 0, SM_TOPERV, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINSUB, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINNODE, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);
    }

    // Testing for Lid Control Infiltration Trench parameters get/set
    BOOST_FIXTURE_TEST_CASE(getset_lidcontrol_IT, FixtureOpenClose_LID)
    {
        open_swmm_model(2);
        int error, lid_index, sub_index;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        string infilTrench = string("IT");
        string subcatch = string("wIT");

        lid_index = swmm_getObjectIndex(SM_LID, (char *)infilTrench.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        sub_index = swmm_getObjectIndex(SM_SUBCATCH, (char *)subcatch.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        // Surface layer get/set check
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.25, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, 0.9);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.9, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0.2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ALPHA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.05359, 0.0001);

        // Storage layer get/set check
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 12, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, 0.15);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.15, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_KSAT, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        // Drain layer get/set
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_COEFF, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_COEFF, 1.0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_COEFF, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.0, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_EXPON, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_EXPON, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_EXPON, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_OFFSET, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_OFFSET, 20);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_OFFSET, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 20, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_DELAY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_DELAY, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_DELAY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HOPEN, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_HOPEN, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HOPEN, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        // Check for immediate overflow option
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 0);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 1);

        // Lid Unit
        error = swmm_getLidUCount(sub_index, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);

        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 50, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_UNITAREA, 1000);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1000, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 10, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FWIDTH, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_INITSAT, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 25, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FROMIMPERV, 75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 75, 0.0001);

        error = swmm_getLidUOption(sub_index, 0, SM_INDEX, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, lid_index);

        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 100);
        error = swmm_setLidUOption(sub_index, 0, SM_NUMBER, 11);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 11);

        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);
        error = swmm_setLidUOption(sub_index, 0, SM_TOPERV, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINSUB, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINNODE, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);
    }

    // Testing for Lid Control Permeable Pavement parameters get/set
    BOOST_FIXTURE_TEST_CASE(getset_lidcontrol_PP, FixtureOpenClose_LID)
    {
        open_swmm_model(3);
        int error, lid_index, sub_index;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        string permPave = string("PP");
        string subcatch = string("wPP");

        lid_index = swmm_getObjectIndex(SM_LID, (char *)permPave.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        sub_index = swmm_getObjectIndex(SM_SUBCATCH, (char *)subcatch.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        // Surface layer get/set check
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.25, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, 0.9);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.9, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0.2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ALPHA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.05359, 0.0001);

        // Pavement layer get/set check
        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_PAVE, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.15, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_PAVE, SM_VOIDFRAC, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_IMPERVFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_PAVE, SM_IMPERVFRAC, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_IMPERVFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_PAVE, SM_KSAT, 75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 75, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(db_value - 0, 0);
        error = swmm_setLidCParam(lid_index, SM_PAVE, SM_CLOGFACTOR, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_REGENDAYS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(db_value - 0, 0);
        error = swmm_setLidCParam(lid_index, SM_PAVE, SM_REGENDAYS, 1);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_REGENDAYS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_REGENDEGREE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(db_value - 0, 0);
        error = swmm_setLidCParam(lid_index, SM_PAVE, SM_REGENDEGREE, 1);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_PAVE, SM_REGENDEGREE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1, 0.0001);

        // Storage layer get/set check
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 12, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, 0.15);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.15, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_KSAT, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        // Drain layer get/set
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_COEFF, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_COEFF, 1.0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_COEFF, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.0, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_EXPON, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_EXPON, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_EXPON, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_OFFSET, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_OFFSET, 20);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_OFFSET, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 20, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_DELAY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_DELAY, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_DELAY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HOPEN, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_HOPEN, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HOPEN, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        // Check for immediate overflow option
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 0);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 1);

        // Lid Unit
        error = swmm_getLidUCount(sub_index, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);

        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 50, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_UNITAREA, 1000);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1000, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 10, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FWIDTH, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_INITSAT, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 25, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FROMIMPERV, 75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 75, 0.0001);

        error = swmm_getLidUOption(sub_index, 0, SM_INDEX, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, lid_index);

        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 100);
        error = swmm_setLidUOption(sub_index, 0, SM_NUMBER, 11);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 11);

        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);
        error = swmm_setLidUOption(sub_index, 0, SM_TOPERV, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINSUB, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINNODE, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);
    }

    // Testing for Lid Control Rain Barrel parameters get/set
    BOOST_FIXTURE_TEST_CASE(getset_lidcontrol_RB, FixtureOpenClose_LID)
    {
        open_swmm_model(4);
        int error, lid_index, sub_index;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        string lid = string("RB");
        string subcatch = string("wRB");

        lid_index = swmm_getObjectIndex(SM_LID, (char *)lid.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        sub_index = swmm_getObjectIndex(SM_SUBCATCH, (char *)subcatch.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        // Storage layer get/set check
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 48, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        // default to value of 1.0 for rain barrels
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, 0.15);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1, 0.0001);

        // default to value of 0.0 for rain barrels
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_KSAT, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        // Drain layer get/set
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_COEFF, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_COEFF, 2.0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_COEFF, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2.0, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_EXPON, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_EXPON, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_EXPON, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_OFFSET, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_OFFSET, 20);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_OFFSET, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 20, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_DELAY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_DELAY, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_DELAY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HOPEN, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_HOPEN, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HOPEN, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        // Check for immediate overflow option
        // Always available to immediate overflow
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 1);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 1);

        // Lid Unit
        error = swmm_getLidUCount(sub_index, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);

        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 12, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_UNITAREA, 1000);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1000, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 10, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FWIDTH, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_INITSAT, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 25, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FROMIMPERV, 75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 75, 0.0001);

        error = swmm_getLidUOption(sub_index, 0, SM_INDEX, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, lid_index);

        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 100);
        error = swmm_setLidUOption(sub_index, 0, SM_NUMBER, 11);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 11);

        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);
        error = swmm_setLidUOption(sub_index, 0, SM_TOPERV, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINSUB, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINNODE, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);
    }

    // Testing for Lid Control Rain Garden parameters get/set
    BOOST_FIXTURE_TEST_CASE(getset_lidcontrol_RG, FixtureOpenClose_LID)
    {
        open_swmm_model(5);
        int error, lid_index, sub_index;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        string lid = string("RG");
        string subcatch = string("wRG");

        lid_index = swmm_getObjectIndex(SM_LID, (char *)lid.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        sub_index = swmm_getObjectIndex(SM_SUBCATCH, (char *)subcatch.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        // Surface layer get/set check
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.25, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, 0.9);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.9, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0.2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ALPHA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.05359, 0.0001);

        // Soil layer get/set
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 12, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_POROSITY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_POROSITY, 0.3);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_POROSITY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.3, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_FIELDCAP, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_FIELDCAP, 0.3);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_FIELDCAP, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.3, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_WILTPOINT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_WILTPOINT, 0.3);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_WILTPOINT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.3, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_KSAT, 0.1);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 10, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_KSLOPE, 20);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_KSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 20, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_SUCTION, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 3.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SOIL, SM_SUCTION, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SOIL, SM_SUCTION, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        // Storage layer get/set check
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        // storage layer thickness was originally zero
        // void frac is default 1.0
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, 0.15);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.15, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_KSAT, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_KSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, 0.75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_STOR, SM_CLOGFACTOR, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.75, 0.0001);

        // Check for immediate overflow option
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 0);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 1);

        // Lid Unit
        error = swmm_getLidUCount(sub_index, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);

        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 50, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_UNITAREA, 1000);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1000, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 10, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FWIDTH, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_INITSAT, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 25, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FROMIMPERV, 75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 75, 0.0001);

        error = swmm_getLidUOption(sub_index, 0, SM_INDEX, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, lid_index);

        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 100);
        error = swmm_setLidUOption(sub_index, 0, SM_NUMBER, 11);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 11);

        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);
        error = swmm_setLidUOption(sub_index, 0, SM_TOPERV, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINSUB, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINNODE, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);
    }

    // Testing for Lid Control Swale parameters get/set
    BOOST_FIXTURE_TEST_CASE(getset_lidcontrol_SWALE, FixtureOpenClose_LID)
    {
        open_swmm_model(6);
        int error, lid_index, sub_index;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        string lid = string("SWALE");
        string subcatch = string("wSWALE");

        lid_index = swmm_getObjectIndex(SM_LID, (char *)lid.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        sub_index = swmm_getObjectIndex(SM_SUBCATCH, (char *)subcatch.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        // Surface layer get/set check
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 12, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.25, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, 0.9);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.9, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0.2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ALPHA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.05359, 0.0001);

        // Check for immediate overflow option
        // Always available to immediate overflow
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 1);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 1);

        // Lid Unit
        error = swmm_getLidUCount(sub_index, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);

        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 500, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_UNITAREA, 1000);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1000, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FWIDTH, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_INITSAT, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 25, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FROMIMPERV, 75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 75, 0.0001);

        error = swmm_getLidUOption(sub_index, 0, SM_INDEX, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, lid_index);

        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 10);
        error = swmm_setLidUOption(sub_index, 0, SM_NUMBER, 11);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 11);

        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);
        error = swmm_setLidUOption(sub_index, 0, SM_TOPERV, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINSUB, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINNODE, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);
    }

    // Testing for Lid Control Roof Disconnection parameters get/set
    BOOST_FIXTURE_TEST_CASE(getset_lidcontrol_RD, FixtureOpenClose_LID)
    {
        open_swmm_model(7);
        int error, lid_index, sub_index;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        string lid = string("RD");
        string subcatch = string("wRD");

        lid_index = swmm_getObjectIndex(SM_LID, (char *)lid.c_str(), &error);
        BOOST_REQUIRE(error == 0);

        sub_index = swmm_getObjectIndex(SM_SUBCATCH, (char *)subcatch.c_str(), &error);
        BOOST_CHECK_EQUAL(error, 0);

        // Surface layer get/set check
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, 100);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_THICKNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 100, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.25, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, 0.9);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_VOIDFRAC, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.9, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.1, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0.2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_SURFSLOPE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_SURFACE, SM_ALPHA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1.05359, 0.0001);

        // Drain layer get/set
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_COEFF, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_COEFF, 2.0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_COEFF, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2.0, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_EXPON, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.5, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_EXPON, 2);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_EXPON, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 2, 0.0001);

        // if storage thickness is zero
        // the offset is changed to zero
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_OFFSET, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_OFFSET, 20);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_OFFSET, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0.0, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_DELAY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 6, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_DELAY, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_DELAY, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HOPEN, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_HOPEN, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HOPEN, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, 7);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCParam(lid_index, SM_DRAIN, SM_HCLOSE, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 7, 0.0001);

        // Check for immediate overflow option
        // No option available for immediate overflow
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 0);
        error = swmm_setLidCParam(lid_index, SM_SURFACE, SM_ROUGHNESS, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidCOverflow(lid_index, &chr_value);
        BOOST_REQUIRE(error == 0);
        BOOST_REQUIRE(chr_value == 0);

        // Lid Unit
        error = swmm_getLidUCount(sub_index, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);

        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 50, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_UNITAREA, 1000);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_UNITAREA, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 1000, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 10, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FWIDTH, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FWIDTH, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 0, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_INITSAT, 5);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_INITSAT, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 5, 0.0001);

        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 25, 0.0001);
        error = swmm_setLidUParam(sub_index, 0, SM_FROMIMPERV, 75);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUParam(sub_index, 0, SM_FROMIMPERV, &db_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_SMALL(db_value - 75, 0.0001);

        error = swmm_getLidUOption(sub_index, 0, SM_INDEX, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, lid_index);

        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 100);
        error = swmm_setLidUOption(sub_index, 0, SM_NUMBER, 11);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_NUMBER, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 11);

        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 1);
        error = swmm_setLidUOption(sub_index, 0, SM_TOPERV, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_TOPERV, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINSUB, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINSUB, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);

        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, -1);
        error = swmm_setLidUOption(sub_index, 0, SM_DRAINNODE, 0);
        BOOST_REQUIRE(error == 0);
        error = swmm_getLidUOption(sub_index, 0, SM_DRAINNODE, &int_value);
        BOOST_REQUIRE(error == 0);
        BOOST_CHECK_EQUAL(int_value, 0);
    }

    // Testing for After Start Errors
    BOOST_FIXTURE_TEST_CASE(sim_after_start_index_check, FixtureBeforeStep_LID)
    {
        open_swmm_model(0);
        int error;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        //Lid Control
        error = swmm_getLidCOverflow(1, &chr_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_getLidCParam(1, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_setLidCParam(1, 0, 0, db_value);
        BOOST_CHECK_EQUAL(error, 505);

        //Lid Unit
        error = swmm_getLidUCount(2, &int_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_getLidUParam(2, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_setLidUParam(2, 0, 0, db_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_getLidUOption(2, 0, 0, &int_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_setLidUOption(2, 0, 0, int_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_getLidUFluxRates(2, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 505);
        error = swmm_getLidUResult(2, 0, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 505);

        //Lid Group
        error = swmm_getLidGResult(2, 14, &db_value);
        BOOST_CHECK_EQUAL(error, 505);
    }

    // Testing for invalid parameter key
    BOOST_FIXTURE_TEST_CASE(sim_after_start_key_check, FixtureBeforeStep_LID)
    {
        open_swmm_model(0);
        int error;
        int int_value = 0;
        double db_value = 0;
        char chr_value = '0';

        //Lid Control
        error = swmm_getLidCParam(0, 0, 100, &db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_setLidCParam(0, 0, 100, db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_getLidCParam(0, 100, 0, &db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_setLidCParam(0, 100, 0, db_value);
        BOOST_CHECK_EQUAL(error, 501);

        //Lid Unit
        error = swmm_getLidUParam(0, 0, 100, &db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_getLidUOption(0, 0, 100, &int_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_getLidUFluxRates(0, 0, 100, &db_value);
        BOOST_CHECK_EQUAL(error, 501);
        error = swmm_getLidUResult(0, 0, 100, &db_value);
        BOOST_CHECK_EQUAL(error, 501);

        //Lid Group
        error = swmm_getLidGResult(0, 100, &db_value);
        BOOST_CHECK_EQUAL(error, 501);
    }

    // Testing for undefined lid usage
    BOOST_FIXTURE_TEST_CASE(sim_after_start_undefined_check, FixtureBeforeStep_LID)
    {
        open_swmm_model(0);
        int error;
        double db_value = 0;

        //Lid Unit
        error = swmm_getLidUFluxRates(0, 1, SM_SURFACE, &db_value);
        BOOST_CHECK_EQUAL(error, 511);
        error = swmm_getLidUResult(0, 1, SM_INFLOW, &db_value);
        BOOST_CHECK_EQUAL(error, 511);

        //Lid Group
        error = swmm_getLidGResult(1, 14, &db_value);
        BOOST_CHECK_EQUAL(error, 511);
    }

BOOST_AUTO_TEST_SUITE_END()
