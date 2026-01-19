#if LV_BUILD_TEST
#include "../lvgl.h"

#include "unity/unity.h"

void setUp(void)
{
    /* Function run before every test */
}

void tearDown(void)
{
    /* Function run after every test */
    lv_obj_clean(lv_screen_active());
}

void test_xml_textarea_with_attrs(void)
{
    lv_obj_t * scr = lv_screen_active();

    const char * textarea1_attrs[] = {
        "text", "This is the text",
        "style_text_align", "center",
        "one_line", "true",
        "width", "400",
        "align", "center",
        NULL, NULL,
    };

    lv_xml_create(scr, "lv_textarea", textarea1_attrs);


    TEST_ASSERT_EQUAL_SCREENSHOT("xml/lv_textarea.png");
}

void test_xml_textarea_password_bullet(void)
{
    lv_obj_t * scr = lv_screen_active();

    const char * textarea_attrs[] = {
        "text", "Secret",
        "password_bullet", "#",
        "password_mode", "true",
        "password_show_time", "1234",
        "cursor_pos", "2",
        NULL, NULL,
    };

    lv_obj_t * textarea = lv_xml_create(scr, "lv_textarea", textarea_attrs);

    TEST_ASSERT_NOT_NULL(textarea);
    TEST_ASSERT_TRUE(lv_textarea_get_password_mode(textarea));
    TEST_ASSERT_EQUAL_UINT32(1234, lv_textarea_get_password_show_time(textarea));
    TEST_ASSERT_EQUAL_UINT32(2, lv_textarea_get_cursor_pos(textarea));
    TEST_ASSERT_EQUAL_STRING("#", lv_textarea_get_password_bullet(textarea));
    TEST_ASSERT_EQUAL_STRING("Secret", lv_textarea_get_text(textarea));
    TEST_ASSERT_EQUAL_STRING("######", lv_label_get_text(lv_textarea_get_label(textarea)));
}

#endif
