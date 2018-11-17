#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义错误类型
typedef unsigned int ErrorType;
#define ERROR_TYPE__PARAMS_NOT_ENOUGH 0
#define ERROR_TYPE__ERROR_IP_ADDRESS_FORMAT 1

// 预定义函数
void endWithError(ErrorType errorType);

/**
 * main()
 * @description main函数
 * @param {int} argc 参数个数
 * @param {char *[]} argv 程序外部传参
 * @return
 */
int main(int argc, char *argv[]) {
    // 参数判断，如果参数小于两个，则说明没有输入IP地址
    if (argc < 2) { endWithError(ERROR_TYPE__PARAMS_NOT_ENOUGH); }

    // 校验 IP 地址格式是否正确
    char *ipAddress = argv[1];
    if (!ipAddress) { endWithError(ERROR_TYPE__ERROR_IP_ADDRESS_FORMAT); }

    return 0;
}

/**
 * endWithError()
 * @description 报错并结束程序
 * @param {ErrorType} errorType 错误类型
 */
void endWithError(ErrorType errorType) {
    // 报错
    switch (errorType) {
        case ERROR_TYPE__PARAMS_NOT_ENOUGH:
            printf("Have no enough params.\n");
            printf("Usage: ping ip_address [-n] [send_time] [-l] [ICMP_package_length]\n");
            break;
        case ERROR_TYPE__ERROR_IP_ADDRESS_FORMAT:
            printf("Error IP address format. Please try again.\n");
            break;
        default:
            printf("Unknown error. Please try again.\n");
            break;
    }
    // 退出程序
    exit(0);
}

/**
 * checkIpAddress()
 * @description 校验IP地址
 * @param {char *} ipAddress IP地址
 * @return {0|1} IP地址是否符合规范
 */
int checkIpAddress(char *ipAddress) {
    int i, count = 0, number;
    char *temp;

    // 拷贝字符串
    char *ipAddressCopy = (char *) malloc((sizeof char) * strlen(ipAddress) + 1);
    for (i = 0; i < strlen(ipAddress); i++) { ipAddressCopy[i] = ipAddress[i]; }
    ipAddressCopy[i] = '\0';

    // 依次分割字符串，看是否有三个点，并且点之间的每一个字符串都满足数字范围
    temp = strtok(ipAddressCopy, ".");
    while (temp != NULL) {
        count++;
        number = atoi(temp);
        if (number == 0 && temp[0] != '0') { return 0; }
        if (!(number >= 0 && number <= 255)) { return 0; }
    }
    if (count != 3) { return 0; }

    return 1;
}
