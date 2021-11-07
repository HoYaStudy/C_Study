#include "gtest/gtest.h"

extern "C" {
#include "message_queue.h"
}

class QueueTest : public ::testing::Test {
 protected:
  QueueTest() { MessageQ_Init(); }
};

TEST_F(QueueTest, testSetGet) {
  // Set
  MESSAGE tMsg;
  tMsg.msgID = 1;
  tMsg.len = 3;
  for (uint8_t i = 0; i < tMsg.len; i++) {
    tMsg.data[i] = i;
  }
  MessageQ_Set(&tMsg);

  // Get
  PMESSAGE ptMsg = NULL;
  ptMsg = MessageQ_Get();
  EXPECT_TRUE(ptMsg != NULL);
  EXPECT_EQ(tMsg.msgID, ptMsg->msgID);
  EXPECT_EQ(tMsg.len, ptMsg->len);
  for (uint8_t i = 0; i < tMsg.len; i++) {
    EXPECT_EQ(tMsg.data[i], ptMsg->data[i]);
  }
}

TEST_F(QueueTest, testFull) {
  // Set
  MESSAGE tMsg;
  tMsg.msgID = 1;
  tMsg.len = 3;
  for (uint8_t i = 0; i < tMsg.len; i++) {
    tMsg.data[i] = i;
  }
  for (uint8_t i = 0; i < MESSAGE_COUNT; i++) {
    MessageQ_Set(&tMsg);
  }
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
