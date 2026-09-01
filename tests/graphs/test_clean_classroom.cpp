#include <gtest/gtest.h>
#include "graphs/clean_classroom.hpp"

TEST(CleanClassroom, BasicExample) {
    // Right then down reaches the single piece of litter on the last unit.
    EXPECT_EQ(minMoves({"S.", "XL"}, 2), 2);
}

TEST(CleanClassroom, ResetPadOnTheWay) {
    // Taking the litter below, refilling on 'R', then crossing to the far
    // corner costs three moves; without the pad the battery would run dry.
    EXPECT_EQ(minMoves({"LS", "RL"}, 4), 3);
}

TEST(CleanClassroom, BatteryTooShortToFinish) {
    // Either piece is reachable on its own, but the wall forces a detour back
    // through the start and the pad is a move too far away.
    EXPECT_EQ(minMoves({"L.S", "RXL"}, 3), -1);
}

TEST(CleanClassroom, NoLitterAtAll) {
    // Nothing to collect, so the robot is already done.
    EXPECT_EQ(minMoves({"S..", "..."}, 3), 0);
    EXPECT_EQ(minMoves({"S"}, 1), 0);
}

TEST(CleanClassroom, AdjacentLitter) {
    EXPECT_EQ(minMoves({"SL"}, 1), 1);
}

TEST(CleanClassroom, LitterSealedBehindWalls) {
    // No route exists at all, however much battery is on hand.
    EXPECT_EQ(minMoves({"SX", "XL"}, 100), -1);
}

TEST(CleanClassroom, BatteryExactlyEnough) {
    // A straight corridor of four moves: four units clear it, three do not.
    EXPECT_EQ(minMoves({"S...L"}, 4), 4);
    EXPECT_EQ(minMoves({"S...L"}, 3), -1);
}

TEST(CleanClassroom, LitterOnBothSidesOfTheStart) {
    // Sweeping left then back across to the right takes three moves, so the
    // battery has to cover the whole trip in one charge.
    EXPECT_EQ(minMoves({"LSL"}, 3), 3);
    EXPECT_EQ(minMoves({"LSL"}, 2), -1);
}

TEST(CleanClassroom, ResetPadUsedTwice) {
    // The pad sits between the two piles, and neither can be reached and left
    // on a single charge, so the robot returns to recharge before the second.
    EXPECT_EQ(minMoves({"L.R.L", "..S.."}, 4), 7);
    // Four moves out of the pad is one short of surviving either round trip.
    EXPECT_EQ(minMoves({"L.R.L", "..S.."}, 3), -1);
}

TEST(CleanClassroom, LitterSweptUpInPassing) {
    // The middle pile is collected simply by walking over it on the way.
    EXPECT_EQ(minMoves({"S", "L", "L"}, 2), 2);
}

TEST(CleanClassroom, BothPilesOnOneSweep) {
    // The two piles are stacked in the last column, so crossing the top row
    // and dropping down collects both in three moves - and three units of
    // battery are exactly enough to do it.
    EXPECT_EQ(minMoves({"S.L", "..L"}, 6), 3);
    EXPECT_EQ(minMoves({"S.L", "..L"}, 3), 3);
    EXPECT_EQ(minMoves({"S.L", "..L"}, 2), -1);
}
