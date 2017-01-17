'''
Takes 'HKU Portal UID' and 'Password' as the command line arguments. Default Webdriver is chromedriver.
Saves a screenshot of the final page after course enrollment.

A script for [lazy] students from HKU to enroll in the pre-selected courses (from the temporary course list) during
the add/drop period. Since I didn't have access to internet during the latest add/drop period, I wrote this code and
scheduled it to run on a server.

@krohak
'''
from selenium import webdriver
import sys,time

browser = webdriver.Chrome('/home/rohak/Projects/Code/HKU/chromedriver')

browser.get('https://hkuportal.hku.hk/login.html')

emailElem = browser.find_element_by_id('username')
username = sys.argv[1]
emailElem.send_keys(username)

passwordElem = browser.find_element_by_id('password')
password = sys.argv[2]
passwordElem.send_keys(password)

passwordElem.submit()

#browser.get('https://sis-eportal.hku.hk/psp/ptlprod/EMPLOYEE/HRMS/c/SA_LEARNER_SERVICES.SSR_SSENRL_CART.GBL?pslnkid=Z_HC_SSR_SSENRL_CART_LNK&FolderPath=PORTAL_ROOT_OBJECT.Z_SIS_MENU.Z_ENROLLMENT.Z_HC_SSR_SSENRL_CART_LNK&IsFolder=false&IgnoreParamTempl=FolderPath%2cIsFolder')

#browser.find_element_by_xpath("//*[type='radio']").click

#sub = browser.find_element_by_id("DERIVED_SSS_SCT_SSR_PB_GO")
#sub = browser.find_element_by_class_name("SSSBUTTON_CONFIRMLINK")

browser.get('https://sis-main.hku.hk/psc/sisprod/EMPLOYEE/HRMS/c/SA_LEARNER_SERVICES.SSR_SSENRL_CART.GBL?Page=SSR_SSENRL_CART&Action=A&ACAD_CAREER=UG&EMPLID=3035242475&INSTITUTION=HKUHK&STRM=4162')


#sub = browser.find_element_by_tag_name("input")
q = browser.find_elements_by_tag_name('a')
for i in q:
    if i.text == 'Proceed To Step 2 Of 3':
    #if i.text == 'search':
        z=i
z.click()


q = browser.find_elements_by_tag_name('a')
for i in q:
    if i.text == 'Finish Enrolling':
        z=i

z.click()

time.sleep(1)
browser.save_screenshot('/home/rohak/Projects/Code/HKU/screenshot.png')
browser.quit()





#sub.submit()

#input("dsdsds")
