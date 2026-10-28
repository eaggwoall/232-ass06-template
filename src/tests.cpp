#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

#include "code.hpp"
#include <iostream>

// ============================================================
// PART 2 Tests: DoublyLinkedList
// ============================================================

/// Create a DoublyLinkedList. Verify length() is 0 on a new list.
void test_new_list_is_empty(void)
{
    DoublyLinkedList list;
    TEST_ASSERT_TRUE_MESSAGE(list.length() == 0, "New list should have length 0");
}

/// Create a DoublyLinkedList. Call pushFrontValue and pushBackValue.
/// Verify length() is 2.
void test_push_increases_length(void)
{
    DoublyLinkedList list;
    list.pushFrontValue(1);
    list.pushBackValue(2);
    TEST_ASSERT_TRUE_MESSAGE(list.length() == 2, "List should have length 2 after two pushes");
}

/// Create an EMPTY DoublyLinkedList.
/// Verify popFrontValue() and popBackValue() both have NO value (has_value() is false).
void test_pop_on_empty_list(void)
{
    DoublyLinkedList list;

    std::optional<NodeValue> frontValue = list.popFrontValue();
    TEST_ASSERT_TRUE_MESSAGE((!frontValue.has_value()), "popFrontValue() on empty list should return std::nullopt");

    std::optional<NodeValue> backValue = list.popBackValue();
    TEST_ASSERT_TRUE_MESSAGE((!backValue.has_value()), "popBackValue() on empty list should return std::nullopt");
}

/// Push 1, 2, 3 with pushBackValue.
/// Verify popBackValue() gives 3, then popFrontValue() gives 1, then length() is 1.
void test_pop_order(void)
{
    DoublyLinkedList list;
    
    list.pushBackValue(1);
    list.pushBackValue(2);
    list.pushBackValue(3);

    std::optional<NodeValue> back = list.popBackValue();

    TEST_ASSERT_TRUE_MESSAGE(back.has_value(), "popBackValue() should return a value");
    TEST_ASSERT_TRUE_MESSAGE((std::get<int>(back.value()) == 3), "popBackValue() should return 3");

    std::optional<NodeValue> front = list.popFrontValue();

    TEST_ASSERT_TRUE_MESSAGE(front.has_value(), "popFrontValue() should return a value");
    TEST_ASSERT_TRUE_MESSAGE((std::get<int>(front.value()) == 1), "popFrontValue() should return 1");

    TEST_ASSERT_TRUE_MESSAGE(list.length() == 1, "List should have length 1 after two pops");
}

/// Push one value, then call deleteValue with a value that is NOT in the list.
/// Verify it returns false and length() does not change.
void test_delete_value_not_found(void)
{
    DoublyLinkedList list;
    list.pushBackValue(1);

    bool deleted = list.deleteValue(2);
    TEST_ASSERT_TRUE_MESSAGE(!deleted, "deleteValue() should return false for a value not in the list");
    TEST_ASSERT_TRUE_MESSAGE(list.length() == 1, "List length should remain unchanged after failed delete");
}

/// Push 1, 2, 3 with pushBackValue. Call deleteValue(2).
/// Verify popBackValue() gives 3 and the next popBackValue() gives 1.
/// (popBackValue follows prevPtr: this fails if you forgot to repair the backward link.)
void test_delete_middle_keeps_links(void)
{
    DoublyLinkedList list;
    
    list.pushBackValue(1);
    list.pushBackValue(2);
    list.pushBackValue(3);

    bool result = list.deleteValue(NodeValue{2});

    TEST_ASSERT_TRUE_MESSAGE(result == 1, "NodeValue index 2 was not deleted");
    
    std::optional<NodeValue> firstBack = list.popBackValue();
    TEST_ASSERT_TRUE_MESSAGE(firstBack.has_value(), "popBackValue should have a value");
    TEST_ASSERT_TRUE_MESSAGE(std::get<int>(firstBack.value()) == 3, "first popBackValue should have value 3");

    std::optional<NodeValue> secondBack = list.popBackValue();
    TEST_ASSERT_TRUE_MESSAGE(secondBack.has_value(), "popBackValue should have a value");
    TEST_ASSERT_TRUE_MESSAGE(std::get<int>(secondBack.value()) == 1, "second popBackValue should have value 1");
}

// ============================================================
// PART 3 Tests: StdDoublyLinkedList
// ============================================================

/// Push 1, 2, 1 with pushBackValue. Call deleteValue(NodeValue{1}).
/// Verify length() is 2 and popFrontValue() gives 2 (only the FIRST 1 was removed).
void test_std_delete_only_first(void)
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}

/// Create an EMPTY StdDoublyLinkedList.
/// Verify popFrontValue() and popBackValue() have NO value and do not crash.
void test_std_pop_on_empty_list(void)
{
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}
