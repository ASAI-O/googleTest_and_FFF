# FFFでよく使うマクロ:
FAKE_VOID_FUNC(func);
FAKE_VOID_FUNC(func, int);
FAKE_VALUE_FUNC(int, func);
FAKE_VALUE_FUNC(int, func, int);
FAKE_VALUE_FUNC(bool, func, int, const char*);

# 呼び出し回数確認:
EXPECT_EQ(my_func_fake.call_count, 1);

# 戻り値設定:
my_func_fake.return_val = 123;

# リセット
RESET_FAKE(my_func);
FFF_RESET_HISTORY();