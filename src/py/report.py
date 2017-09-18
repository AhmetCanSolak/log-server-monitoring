#!/usr/bin/env python3

# Read the extracted information
lines = []
with open("results/data/numeric_values.txt") as f:
    for line in f:
        lines.append(line)

NAMESPACE_UNIQUE_IP = str(lines[0])
NAMESPACE_UNIQUE_ID = str(lines[1])
NAMESPACE_UNIQUE_GB = str(lines[2])
NAMESPACE_MOST_IP = str(lines[3])
NAMESPACE_MOST_ID = str(lines[4])

BIT_RATE_HISTOGRAM = "../images/bitRate.png"
BROWSER_TYPE_HISTOGRAM = "../images/browserType.png"
HTTP_STATUS_HISTOGRAM = "../images/httpStatus.png"

final_report = """
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="AhmetCanSolak">

    <title>Log Server</title>

    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
    <link rel="stylesheet" href="report.css" media="screen" title="no title">
    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
        <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->
</head>

<body>

    <!-- Full Width Image Header -->
    <header class="header-image">
        <div class="headline">
            <div class="container">
                <h1></h1>
                <h2>Welcome to Log Server</h2>
            </div>
        </div>
    </header>

    <!-- Page Content -->
    <div class="container">

        <hr class="featurette-divider">

        <!-- Zeroth Featurette -->
        <div class="" id="">
            <div class="text-center">
            <img class=" img-responsive rounded" src="https://res.cloudinary.com/crunchbase-production/image/upload/v1397190811/1baba6d4132689c8fac4a54312fe901d.jpg">
            </div>
              <!-- Table -->
            <table class="table table-striped">
                <thead>
                  <tr>
                    <th>Metrics</th>
                    <th>Results</th>
                  </tr>
                </thead>
                <tbody>
                  <tr>
                    <td># of unique IP:</td>
                    <td>""" + NAMESPACE_UNIQUE_IP + """</td>
                  </tr>
                  <tr>
                    <td># of unique contentID:</td>
                    <td>""" + NAMESPACE_UNIQUE_ID + """</td>
                  </tr>
                  <tr>
                    <td>Total amount of data sent in GB:</td>
                    <td>""" + NAMESPACE_UNIQUE_GB + """</td>
                  </tr>
                  <tr>
                    <td>The most viewer's IP:</td>
                    <td>""" + NAMESPACE_MOST_IP + """</td>
                  </tr>
                  <tr>
                    <td>The most viewed content's ID:</td>
                    <td>""" + NAMESPACE_MOST_ID + """</td>
                  </tr>
                </tbody>
              </table>
        </div>

        <hr class="featurette-divider">

        <!-- First Featurette -->
        <div class="featurette" id="about">
            <img class="featurette-image img-responsive pull-right" src=" """ + BIT_RATE_HISTOGRAM + """ ">
            <h2 class="featurette-heading">Content BitRate Distribution Chart
            </h2>
        </div>

        <hr class="featurette-divider">

        <!-- Second Featurette -->
        <div class="featurette" id="services">
            <img class="featurette-image img-responsive pull-left" src=" """ + BROWSER_TYPE_HISTOGRAM + """ ">
            <h2 class="featurette-heading">(Most Used Ones) Browser Type Distribution Chart
            </h2>
        </div>

        <hr class="featurette-divider">

        <!-- Third Featurette -->
        <div class="featurette" id="contact">
            <img class="featurette-image img-responsive pull-right" src=" """ + HTTP_STATUS_HISTOGRAM + """ ">
            <h2 class="featurette-heading">HTTP Status Distribution Chart
            </h2>
        </div>

        <hr class="featurette-divider">

        <h4>This report will be up-to-date as soon as you run this software for each log...</h4>

        <!-- Footer -->
        <footer>
            <div class="row">
                <div class="col-lg-12">
                    <p>Copyright &copy; AhmetCanSolak, June 2017</p>
                </div>
            </div>
        </footer>

    </div>
    <!-- /.container -->

    <!-- jQuery -->
    <script src="http://code.jquery.com/jquery-3.2.1.min.js"></script>
    <!-- Latest compiled and minified JavaScript -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>

</body>

</html>

"""
file = open("results/report/report.html","w")
file.write(final_report)
file.close()
