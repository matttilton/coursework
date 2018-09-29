"""
Matthew Tilton
9-28-18
"""
import md5
import sys
import base64
import binascii

filepath = '/home/mtilton/Downloads/corrupted.docx'
correcthash = "906461e9d0a2716fa16b2420af1e8d53"

JPEGHEADER = b"\xFF\xD8\xFF"
JPEGFOOTER = b"\xFF\xD9"
PDFHEADER = b"\x25\x50\x44\x46"
PDFFOOTER1 = b"\x0A\x25\x25\x45\x4F\x46"
PDFFOOTER2 = b"\x0A\x25\x25\x45\x4F\x46\x0A"
PDFFOOTER3 = b"\x0D\x0A\x25\x25\x45\x4F\x46\x0D\x0A"
PDFFOOTER4 = b"\x0D\x25\x25\x45\x4F\x46\x0D"
GIFHEADER = b"\x47\x49\x46\x38\x39\x61"
GIFFOOTER = b"\x00\x3B"
PNGHEADER = b"\x89\x50\x4E\x47\x0D\x0A\x1A\x0A"
PNGFOOTER = b"\x49\x45\x4E\x44\xAE\x42\x60\x82"
DOCXHEADER = b"\x50\x4B\x03\x04\x14\x00\x06\x00"
# docx doesnt technically have a footer but this is usually 18 bytes before the end of the file
DOCXFOOTER = b"\x50\x4B\x05\x06"

correcthashesforfiles = ['c3a04e65e43b4a862b010927fae9aab1', '3b2f3b12ee4b04d4d0384adeee21e4d4',
                         '06d08f17d7b2efbc0dc0d303398196d0', 'aec49002f8b02c2099152df1ec18b6c1']


def gethash(file):
    filehash = md5.new()
    filehash.update(file)
    filehash.digest()
    return filehash.hexdigest()


file = open(filepath, 'rb').read()

filehash = gethash(file)

if filehash != correcthash:
    print 'File hash is incorrect'
    sys.exit(-1)
else:
    print 'File hash is correct continuing'
    print 'file length is ' + str(len(file))

convertedtohex = base64.b64decode(file)


def find_all_files(head, foot, extension):
    # find possible jpeg headers
    possible_head_locations = []
    start = 0
    while convertedtohex.find(head, start) != -1:
        location = convertedtohex.find(head, start)
        possible_head_locations.append(location)
        start = location + 1

    # find possible jpeg footers
    possible_foot_locations = []
    start = 0
    while convertedtohex.find(foot, start) != -1:
        location = convertedtohex.find(foot, start)
        possible_foot_locations.append(location + len(foot))
        start = location + 1

    count = 0
    # print possible_foot_locations
    # print possible_head_locations
    for header in possible_head_locations:
        for footer in possible_foot_locations:
            if header < footer:
                # print footer - header
                footerextension = 0
                if extension == ".docx":
                    footerextension = 18
                datatowrite = convertedtohex[header:footer + footerextension]
                if len(datatowrite) != 0:
                    name = gethash(datatowrite)
                    if (name in correcthashesforfiles):
                        print 'found a correct file'
                        name += 'correct'
                    f = open('results/' + str(name) + extension, 'wb')
                    f.write(datatowrite)
            count += 1


find_all_files(JPEGHEADER, JPEGFOOTER, '.jpg')
find_all_files(PDFHEADER, PDFFOOTER1, '.pdf')
find_all_files(PDFHEADER, PDFFOOTER2, '.pdf')
find_all_files(PDFHEADER, PDFFOOTER3, '.pdf')
find_all_files(PDFHEADER, PDFFOOTER4, '.pdf')
find_all_files(GIFHEADER, GIFFOOTER, '.gif')
find_all_files(PNGHEADER, PNGFOOTER, '.png')
find_all_files(DOCXHEADER, DOCXFOOTER, '.docx')
