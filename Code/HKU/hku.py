from selenium import webdriver
import sys

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

browser.save_screenshot('screenshot.png')
browser.quit()


#sub.submit()

#input("dsdsds")
