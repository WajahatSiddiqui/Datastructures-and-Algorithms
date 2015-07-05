#include "List.h"
#include <string>

void setup() {
}


void testInsert(int data) {
    cout<<__FUNCTION__<<endl;
}

void testInsert(int data, int position) {
    cout<<__FUNCTION__<<endl;
}

void testPush(int data) {
    cout<<__FUNCTION__<<endl;
}

void testDeleteNode(int data) {
    cout<<__FUNCTION__<<endl;
}


void runTestCase(string testCase) {
}

void runAllTestCases() {
    setup();
    testInsert(2);
    testInsert(3, 2);
    testPush(3);
    testDeleteNode(2);
}

int main(int argc, char *argv[]) {
    if (argc > 1 && argv[1] != NULL)
        runTestCase(argv[1]);

    runAllTestCases();
    return 0;
}
